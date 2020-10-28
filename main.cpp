#include <iostream>
#include <fstream>
#include <boost/program_options.hpp>

using namespace std;
namespace po = boost::program_options;


void generate_file()
{
	string filename = "generated.txt";
	std::ofstream ostrm(filename, std::ios::binary);
	ostrm << 123 << "abc" << '\n';      
}



int main(int ac, char* av[])
{
	po::options_description desc("Allowed options");
	desc.add_options()
	    ("help", "shows this help message")
	    ("generate", "generate file")
	;

	po::variables_map vm;
	po::store(po::parse_command_line(ac, av, desc), vm);
	po::notify(vm);    

	if (vm.size() == 0)
	{
		cout << desc << '\n';
	}
	if (vm.count("help")) 
	{
	    cout << desc << "\n";
	    return 1;
	}
	if (vm.count("generate")) 
	{
	    cout << "Щас будем генерировать файл " << ".\n";
	    generate_file();
	} 
	
}