#include <iostream>
#include <fstream>
#include <random>
#include <boost/program_options.hpp>

#define MAX_PACKET_SIZE 100

using namespace std;
namespace po = boost::program_options;

std::vector<std::string> v;

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
	if (!ostrm.is_open()) 
	{
    	std::cout << "failed to open " << filename << '\n';
    } 
    else
    {
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
}

std::string leading_zeroes(int i)
{
	if (i < 10)
		return "000" + to_string(i);
	else if (i < 100)
		return "00" + to_string(i);
	else if (i < 1000)
		return "0" + to_string(i);
	else
		return to_string(i);
}

void split_file_into_packets()
{
	string filename = "generated.txt";
	std::ifstream istrm(filename, std::ios::binary);
	if (!istrm.is_open()) 
	{
    	std::cout << "failed to open " << filename << '\n';
    } 
    else
    {
		int i = 1;
     	char s[95];
		//istringstream s(95, '\0'); 

		while (istrm >> s)
		{
			v.push_back(leading_zeroes(i) + "_" + s);
			i++;
		}

		for (auto elem : v)
			cout << elem << endl;
	}
}

int main(int ac, char* av[])
{
	po::options_description desc("Allowed options");
	desc.add_options()
	    ("help", "shows this help message")
	    ("generate", "generate file")
	    ("split", "split file")
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
	if (vm.count("split")) 
	{
	    cout << "Щас будем разбивать на пакеты " << ".\n";
	    split_file_into_packets();
	} 
	
}