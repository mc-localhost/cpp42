#include "easyfind.hpp"
#include <vector>
#include <array>
#include <list>

#define RESET	"\e[0m"
#define RED		"\e[41m"
#define PURPLE	"\e[35m"

int main(void)
{
	try
	{
		std::cout << PURPLE << "Vector check" << RESET << std::endl;
		std::vector<int> v = {8, 4, 5, 9};
		std::cout << "0: " << *easyfind(v, 0) << std::endl;
		std::cout << "9: " << *easyfind(v, 9) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << PURPLE << "Array check" << RESET << std::endl;
		std::array<int, 4> arr = {1, 1, 2, 3};
		std::cout << "1: " << *easyfind(arr, 1) << std::endl;
		std::cout << "3: " << *easyfind(arr, 3) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << PURPLE << "Const list check" << RESET << std::endl;
		const std::list<int>	l = {21, 22, 23, 24, 25};
		std::cout << "25: " << *easyfind(l, 25) << std::endl;
		std::cout << "3: " << *easyfind(l, 3) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	return 0;
}
