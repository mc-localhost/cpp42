#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		std::cerr << "Wrong number of arguments: must be only 1" << std::endl;
	else
		ScalarConverter::convert(argv[1]);
	return 0;
}
