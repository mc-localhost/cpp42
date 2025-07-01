#include "Span.hpp"

#define RESET	"\e[0m"
#define RED		"\e[41m"
#define PURPLE	"\e[35m"

int main(void)
{
// --------------CHECK FROM THE SUBJECT--------------------
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
// ------------------------------------------------
	std::cout << PURPLE << "Copy check" << RESET << std::endl;
	sp.printNumbers();
	Span sp_copy = sp;
	sp_copy.printNumbers();

	try
	{
		std::cout << PURPLE << "Constructor with 0, add number check" << RESET << std::endl;
		Span zero_span(0);
		Span zero_copy(zero_span);
		zero_span.printNumbers();
		zero_span.addNumber(2);
	}
	catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << PURPLE << "Constructor with 10, add numbers from vectors" << RESET << std::endl;
		Span my_span(10);
		std::vector<int> insert_that = {1, 2, 10, 45, 0};
		my_span.addNumber(2);
		my_span.addNumber(1);
		my_span.addManyNumbers(insert_that);
		my_span.printNumbers();
	}
	catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << PURPLE << "Generate 10.000 random numbers, calculate spans" << RESET << std::endl;
		Span rand_span(10000);
		rand_span.addRandomNumbers(10000);
		rand_span.printNumbers();
		std::cout << rand_span.shortestSpan() << std::endl;
		std::cout << rand_span.longestSpan() << std::endl;
		rand_span.addNumber(2);
	}
	catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	return 0;
}