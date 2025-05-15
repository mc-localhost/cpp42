#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>
# include <utility>

class WrongAnimal
{
	protected:
		std::string _type;
	public:
		// Constructors
		WrongAnimal();
		WrongAnimal(const WrongAnimal &copy);
		WrongAnimal( std::string type);
		
		// Destructor
		virtual ~WrongAnimal();
		
		// Operators
		WrongAnimal & operator=(WrongAnimal assign);
		
		// Getters / Setters
		std::string getType() const;
		void setType( std::string type);

		void makeSound() const;
		
};

#endif