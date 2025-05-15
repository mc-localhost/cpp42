#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include <utility>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;
	public:
		Dog();
		virtual ~Dog();
		Dog(const Dog &copy);
		Dog & operator=(Dog assign);

		void makeSound() const override;
		Brain & getBrain() const override;
};

#endif