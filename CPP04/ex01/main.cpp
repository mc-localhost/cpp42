#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << "*	 CLEANING UP	*" << std::endl;
	delete dog;
	delete cat;

	std::cout << "*	 ANIMAL ARRAY INCOMING	*" << std::endl;
	int size = 10;
	Animal *animals[size];
	int i;
	for (i = 0; i < size; ++i)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	std::cout << "*	 CAT SOUNDS INCOMING	*" << std::endl;
	for (i = 0; i < size; ++i)
	{
		if (animals[i]->getType() == "Cat")
		{
			animals[i]->makeSound();
			animals[i]->getBrain().printFirstIdea();
		}
	}
	std::cout << "*	 CLEANING UP	*" << std::endl;
	for (i = 0; i < size; ++i)
	{
		delete animals[i];
	}

	std::cout << "*	 COPY CHECK	WITH NEW*" << std::endl;
	Cat *kotik = new Cat();
	Cat *kotik_copy = new Cat(*kotik);
	kotik_copy->getBrain().printFirstIdea();
	std::cout << "*	 CLEANING UP	*" << std::endl;
	delete kotik;
	delete kotik_copy;

	std::cout << "*	 COPY CHECK	W/O NEW*" << std::endl;
	Dog sobachka;
	Dog sobachka_copy = sobachka;
	std::cout << "*	 CLEANING UP	*" << std::endl;

	return 0;
}
