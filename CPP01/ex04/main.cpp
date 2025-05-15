/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:03:29 by vvasiuko          #+#    #+#             */
/*   Updated: 2025/04/05 16:01:48 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

static std::string replace(const std::string str, const std::string s1, const std::string s2)
{
	std::string res = str;
	size_t n = res.find(s1);
	while (n != res.npos){
		res = res.substr(0, n) + s2 + res.substr(n + s1.length());
		n = res.find(s1, n + s2.length()); //reset finding position to not get into an infinite loop (./files in t t || ./files in t that)
	}
	return res;
}

static int input_check(const std::string infile, const std::string s1)
{
	if (s1.length() == 0) {
		std::cerr << "Wrong input: string to replace (s1) is empty" << std::endl;
		return 1;
	}
	else if (infile.length() == 0) {
		std::cerr << "Wrong input: file name is empty" << std::endl;
		return 1;
	}
	return 0;
}

int main(int argc, char** argv)
{
	if (argc != 4){
		std::cerr << "Wrong number of arguments: must be filename, s1, s2" << std::endl;
		return 1;
	}
	std::string infile = argv[1];
	std::string outfile = infile + ".replace";
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (input_check(infile, s1))
		return 1;
	std::ifstream ifs(infile);
	if (!ifs.is_open()){
		std::cerr << "Error opening file for reading" << std::endl;
		return 1;
	}
	std::ofstream ofs(outfile);
	if (!ofs.is_open()){
		std::cerr << "Error opening file for writing" << std::endl;
		return 1;
	}

	std::string line;
	while (std::getline(ifs, line)) {
		ofs << replace(line, s1, s2);
		if (!ifs.eof())
			ofs << std::endl;
		line.clear();
	}
	ifs.close();
	ofs.close();

	return 0;
}