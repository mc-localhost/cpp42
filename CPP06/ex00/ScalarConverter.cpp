#include "ScalarConverter.hpp"

/*
Output format:
	char: '*'
	int: 42
	float: 42.0f
	double: 42.0
*/

static void print_impossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

static void print_int(int value)
{
	std::cout << "int: " << value << std::endl;
}

static void print_float(float value, int p)
{
	if (p == 0)
		std::cout << std::fixed << "float: " << value << "f" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(p) << "float: " << value << "f" << std::endl;
}

static void print_char(int value)
{
	if (value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (isprint(value))
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

static void print_double(double value)
{
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

static void convert_char(std::string input)
{
	std::cout << "char: '" << input[0] << "'" << std::endl;

	int c = input[0];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);
	print_int(i);
	print_float(f, 1);
	print_double(d);
	
}

static void convert_int(std::string input)
{
	try
	{
		int stoi_res = stoi(input);

		float f = static_cast<float>(stoi_res);
		double d = static_cast<double>(stoi_res);
		print_char(stoi_res);
		print_int(stoi_res);
		print_float(f, 1);
		print_double(d);
	}
	/*
		std::invalid_argument if no conversion could be performed
		std::out_of_range if the converted value would fall out of the range of the result type
	*/
	catch (const std::exception& e)
	{
		print_impossible();
	}
	/*
	In theory, if input is out_of_range for int, it still may be possible to convert to float,
	but according to the task we should be explicitly converting to other types, so...
	*/
}

static void convert_float(std::string input)
{
	try
	{
		float stof_res = stof(input);

		int i = static_cast<int>(stof_res);
		double d = static_cast<double>(stof_res);
		print_char(i);
	
		std::regex re_pseudo("^([+-]?inff|nanf)$");
		if (!std::regex_match(input, re_pseudo))
			print_int(i);
		else
			std::cout << "int: impossible" << std::endl;

		print_float(stof_res, 0);
		print_double(d);
	}
	catch (const std::exception& e)
	{
		print_impossible();
	}
}

static void convert_double(std::string input)
{
	try
	{
		double stod_res = stod(input);

		int i = static_cast<int>(stod_res);
		float f = static_cast<float>(stod_res);
		print_char(i);
		std::regex re_pseudo("^([+-]?inf|nan)$");
		if (!std::regex_match(input, re_pseudo))
			print_int(i);
		else
			std::cout << "int: impossible" << std::endl;
		print_float(f, 0);
		print_double(stod_res);
	}
	catch (const std::exception& e)
	{
		print_impossible();
	}
}

ScalarConverter::EType determine_type(const std::string &input)
{
	ScalarConverter::EType result = ScalarConverter::EType::T_UNKNOWN;

	// https://en.cppreference.com/w/cpp/language/string_literal.html - part about Raw string literal
	std::regex re_int(R"(^([+-]?\d+)$)");
    std::regex re_float(R"(^([+-]?(\d+\.\d*|\.\d+|\d+)f|[+-]?inff|nanf)$)");
    std::regex re_double(R"(^([+-]?(\d+\.\d*|\.\d+|\d+)|[+-]?inf|nan)$)");

	if (input.length() == 1 && !isdigit(input[0]))
		result = ScalarConverter::EType::T_CHAR;
	else if (std::regex_match(input, re_int))
		result = ScalarConverter::EType::T_INT;
	else if (std::regex_match(input, re_float))
		result = ScalarConverter::EType::T_FLOAT;
	else if (std::regex_match(input, re_double))
		result = ScalarConverter::EType::T_DOUBLE;
	return (result);
}

void ScalarConverter::convert(std::string input)
{
	const auto default_precision{std::cout.precision()};
	// https://en.cppreference.com/w/cpp/io/manip/setprecision

	EType t = determine_type(input);
	switch(t)
	{
		case EType::T_UNKNOWN  : print_impossible();   break;
		case EType::T_CHAR: convert_char(input); break;
		case EType::T_INT : convert_int(input);  break;
		case EType::T_FLOAT : convert_float(input);  break;
		case EType::T_DOUBLE : convert_double(input);  break;
	}

	std::cout << std::setprecision(default_precision);
}
