#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include <utility>
#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		virtual ~Dog();
		Dog(const Dog &copy);
		Dog & operator=(Dog assign);

		void makeSound() const override;
		
};

#endif