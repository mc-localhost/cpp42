
#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include <utility>
#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		virtual ~Cat();
		Cat(const Cat &copy);
		Cat & operator=(Cat assign);

		void makeSound() const override;
		
};

#endif