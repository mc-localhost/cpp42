#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include <utility>
# include "Brain.hpp"

class Animal
{
	protected:
		std::string _type;
	public:
		// Constructors
		Animal();
		Animal(const Animal &copy);
		Animal( std::string type);
		
		// Destructor
		virtual ~Animal();
		
		// Operators
		Animal & operator=(const Animal &assign);
		
		// Getters / Setters
		std::string getType() const;
		void setType( std::string type);

		virtual void makeSound() const;
		virtual Brain & getBrain() const = 0; //to be able to use when cat/dog is declared as animal
		
};

#endif