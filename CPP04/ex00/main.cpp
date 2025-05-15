#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
	
	std::cout << "*	WRONG CAT CHECK		*" << std::endl;
	const WrongAnimal* k = new WrongCat();
	k->makeSound();
	const WrongCat* l = new WrongCat();
	l->makeSound();
	
	delete k;
	delete l;

	return 0;
}
