#include "Array.hpp"
#include "../ex01/iter.hpp"
#include <iostream>

#define RESET	"\e[0m"
#define RED		"\e[41m"
#define PURPLE	"\e[35m"

template <typename T, typename F>
void iter(Array<T> &array, F func) // Array-specific version of iter from ex01
{
	for (unsigned int i = 0; i < array.size(); i++)
		func(array[i]);
}

int main(void)
{
	std::cout << PURPLE << "Const check" << RESET << std::endl;
	const Array<int> int_array_const(3);
	std::cout << "size: " << int_array_const.size() << std::endl;
	std::cout << int_array_const[2] << std::endl;
	std::cout << PURPLE << "yay const works\n" << RESET << std::endl;

	std::cout << PURPLE << "Size = 0 check" << RESET << std::endl;
	const Array<int> int_array_zero(0);
	const Array<int> int_array_zero_copy = int_array_zero;
	std::cout << "size: " << int_array_zero.size() << std::endl;
	std::cout << PURPLE << "yay zero works\n" << RESET << std::endl;

	Array<int> int_array[8]; // creates 8 Array objects
	// Array<int> int_array_1(); // creates a function that returns Array
	Array<int> int_array_2(5); // creates a single Array object with 5 elements
	Array<int> int_array_3; // creates an empty Array object using default constructor

	std::cout << "C-style array of 8 empty Arrays" << std::endl;
	iter(int_array, sizeof(int_array)/sizeof(int_array[0]),
		[](Array<int> &arr){ std::cout << arr.size() << " ";} );
	std::cout << std::endl;

	std::cout << "Regular empty Array of 5 elements" << std::endl;
	iter(int_array_2,
		[](int &x){ std::cout << x << " ";} );
	std::cout << std::endl;

	std::cout << "Empty Array of size 0" << std::endl;
	iter(int_array_3,
		[](int &x){ std::cout << x << "hi im empty";} );
	std::cout << std::endl;

	std::cout << PURPLE << "Out of bounds check" << RESET << std::endl;
	try
	{
		std::cout << int_array_2[10] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	
	std::cout << PURPLE << "Copy constructor check" << RESET << std::endl;
	Array<int> original(3);
	// for (unsigned int i = 0; i < original.size(); i++)
	// 	original[i] = 3;
	iter(original,
		[](int &x){ x = 3; } );
	
	std::cout << PURPLE << "Array gets copied and changed afterwards..." << RESET << std::endl;
	Array<int> copy(original);
	original[0] = 777;
	
	std::cout << "Original Array: ";
	iter(original,
		[](int &x){ std::cout << x << " ";} );
	std::cout << std::endl;

	std::cout << "Copied Array: ";
	iter(copy, 
		[](int &x){ std::cout << x << " ";} );
	std::cout << std::endl;

	std::cout << PURPLE << "Assignment operator check" << RESET << std::endl;
	std::cout << PURPLE << "Array gets copied and changed afterwards..." << RESET << std::endl;
	Array<int> assigned = copy;
	copy[0] = 69;
	
	std::cout << "Copied Array: ";
	iter(copy, 
		[](int &x){ std::cout << x << " ";} );
	std::cout << std::endl;

	std::cout << "Assigned Array: ";
	iter(assigned,
		[](int &x){ std::cout << x << " ";} );
	std::cout << std::endl;

	/*
	More fun stuff from the subject...
	Tip: Try to compile int * a = new int(); then display *a.
	*/
	std::cout << PURPLE << "Small thing from the subject" << RESET << std::endl;
	int *a = new int(); // will be 0
	std::cout << *a << "\n";
	delete a;
	int *b = new int; // will be random on Linux
	std::cout << *b << "\n";
	delete b;

	return 0;
}

/*
Checked during evaluation
*/
// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }