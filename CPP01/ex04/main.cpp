/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 15:18:03 by smariapp          #+#    #+#             */
/*   Updated: 2026/06/25 17:08:03 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "please use this format\n./Sifl filename s1 s2" <<std::endl;
		return 1;
	}
	
	std::ifstream infile(argv[1]);
	if(!infile)
	{
		std::cout << "use a working file...\n";
		return 1;
	}
	
	std::string arg = argv[1];
	std::string outfileName;
	/* unsigned long dot = (arg).find_first_of(".");	
	if (dot < arg.size())
		outfileName = arg.substr(0, dot+1) + "replace";
	else */
		outfileName = arg + ".replace";
	std::ofstream outfile(outfileName.c_str());
	if(!outfile)
	{
		std::cout << "something went wrong in creating an outfile, try again later\n";
		infile.close();
		return 1;
	}
	
	std::string line;
	std::string needle = argv[2];
	int push = needle.size();
	while (std::getline(infile, line))
	{
		std::string result = "";
		while (line.size() > 0)
		{
			std::size_t found = line.find(needle);
			if (found != std::string::npos)
			{
				result += line.substr(0, found);
				result += argv[3];
				line = line.substr(found + push);
			}
			else
			{
				result += line;
				break;
			}
		}
		outfile << result << "\n";
	}
	infile.close();
	outfile.close();
}