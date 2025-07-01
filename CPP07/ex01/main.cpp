#include "iter.hpp"
#include <string>
#include <limits>

void print_string(std::string str)
{
	std::cout << str;
}

float mult_2(float f)
{
	std::cout << f << " ";
	return f * 2;
}

int main(void)
{
	std::string string_array[] = {"I ", "am ", "tired ", "\n"};
	float float_array[] = {0.1f, 12.f, std::numeric_limits<float>::infinity()};

	iter(string_array, 4, print_string);
	iter(float_array, 3, mult_2);
	std::cout << std::endl;

	return 0;
}

/*
Checked during evaluation
*/

// class Awesome
// {
//   public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//   private:
//     int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
//   o << rhs.get();
//   return o;
// }

// template< typename T >
// void print( T& x )
// {
//   std::cout << x << std::endl;
//   return;
// }

// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };
//   Awesome tab2[5];

//   iter( tab, 5, print<const int> );
//   iter( tab2, 5, print<Awesome> );

//   return 0;
// }

