#include <iostream>
#include <string>
#include <fstream>

std::string ft_replace(std::string std_in,char **av)
{
	int start = 0;
	std::string av_two;
	std::string to_find;

	av_two.append(av[3]);

	to_find.append(av[2]);
	start = std_in.find(av[2],start);
	while (start != -1)
	{
		std_in.erase(start, to_find.length());
		std_in.insert(start, av[3]);
		start = std_in.find(av[2], start + av_two.length());
	}
	return (std_in);
}

int main(int ac, char **av)
{
	std::string line;
    std::ifstream infile;
    std::ofstream outfile;
	std::string str_out;
	std::string outfilename;
	std::string av_three;
	std::string av_two;
	std::string tmp;

	if (ac != 4)
	{
		std::cout << "wrong arg" << std::endl;
		return (1);
	}
	av_two.append(av[2]);
	av_three.append(av[3]);
	if (av_three.size() == 0 || av_two.size() == 0)
	{
		std::cout << "wrong arg" << std::endl;
		return (1);
	}
	infile.open(av[1]);
	if (infile)    
    {
		outfilename.append(av[1]).append(".replace");
		char* fd_out = const_cast<char*>(outfilename.c_str());
		outfile.open((char *)fd_out);
		while(std::getline(infile,line))
		{
			if (line.size() != 0)
			{
				tmp.append(line);
				tmp.append("\n");
			}
		}
		str_out = ft_replace(tmp, av);
		outfile << str_out;
	}
    else
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    return (0);
}