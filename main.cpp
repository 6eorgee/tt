#include <iostream>
#include <fstream>
#include <random>
#include <boost/program_options.hpp>

#define MAX_PACKET_SIZE 100

using namespace std;
namespace po = boost::program_options;


int random_number(int max = 10 * MAX_PACKET_SIZE)
{
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, max);
    return uniform_dist(e1);
}

void generate_file()
{
	string filename = "generated.txt";
	std::ofstream ostrm(filename, std::ios::binary);

	int str_count = 100 + random_number(50);
	for (int i = 0; i < str_count; i++)
	{
		int str_len = random_number();
		for (int j = 0; j < str_len; j++)
		{
			ostrm << j % 10;
		}
		ostrm << '\n';
	}
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