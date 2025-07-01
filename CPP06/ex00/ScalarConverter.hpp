#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip> // for percision
#include <climits> // for INT_MAX, INT_MIN
#include <regex> // for regular expressions 

class ScalarConverter
{
	/*
	Subject says this class should have only 1 static method, so...
	*/
	// static EType determine_type(const std::string &input);
	// static void convert_char(std::string input);
	// static void convert_int(std::string input);
	// static void convert_float(std::string input);
	// static void convert_double(std::string input);

	// static void print_impossible();
	// static void print_char(int value);
    // static void print_int(int value);
    // static void print_float(float value, int p);
    // static void print_double(double value);
	
	ScalarConverter() = delete;
	~ScalarConverter() = delete;
	ScalarConverter(const ScalarConverter & converter) = delete;
	ScalarConverter & operator=(const ScalarConverter & converter) = delete;

	public:
	/*
	Conventional enums implicitly convert to int,
	hence enum class usage is considered safer.

	Example: 
		Color r = Color::blue;
		int n = r; // error: no implicit conversion from scoped enum to int
		int n = static_cast<int>(r); // OK, n = 21
	*/
		enum class EType {
			T_UNKNOWN,
			T_CHAR,
			T_INT,
			T_FLOAT,
			T_DOUBLE
		};

		static void convert(std::string input);
};
