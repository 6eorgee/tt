#include <iostream>
#include <fstream>
#include <boost/program_options.hpp>


using namespace std;
namespace po = boost::program_options;


int main(int ac, char* av[])
{

	// Declare the supported options.
	po::options_description desc("Allowed options");
	desc.add_options()
	    ("help", "produce help message")
	    ("compression", po::value<int>(), "set compression level")
	    ("generate", "generate file")
	;

	po::variables_map vm;
	po::store(po::parse_command_line(ac, av, desc), vm);
	po::notify(vm);    

	if (vm.count("help")) 
	{
	    cout << desc << "\n";
	    return 1;
	}

	if (vm.count("compression")) 
	{
	    cout << "Compression level was set to " << vm["compression"].as<int>() << ".\n";
	} 
	// else 
	// {
	//     cout << "Compression level was not set.\n";
	// }
	if (vm.count("generate")) 
	{
	    cout << "Щас будем генерировать файл " << ".\n";
	} 
	
	// string filename = "main.cpp";
	// ifstream file(filename, ios::binary);

	// if (!file.is_open()) 
	// {
	// 	cout << "failed to open " << filename << '\n';
	// } 
	// else 
	// {
	// 	string line;
	// 	while (getline(file, line))  
	// 	 	cout << line << '\n';
	// }

	// file.close();

}