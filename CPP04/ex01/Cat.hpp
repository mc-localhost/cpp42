
#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include <utility>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *brain;
	public:
		Cat();
		virtual ~Cat();
		Cat(const Cat &copy);
		Cat & operator=(Cat assign);

		void makeSound() const override;
		Brain & getBrain() const override;
};

#endif