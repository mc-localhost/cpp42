#include <iostream>
// #include <typeinfo> // see usage later in main

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	if (std::rand() % 2 && std::rand() % 3)
		return new A;
	else if (std::rand() % 2)
		return new B;
	else
		return new C;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
        std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
	else
		std::cout << "Type unknown: downcast from Base unsuccessful\n";
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A\n";
		return;
	}
	catch (std::exception &e) {(void)e;}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B\n";
		return;
	}
	catch (std::exception &e) {(void)e;}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C\n";
		return;
	}
	catch (std::exception &e) {(void)e;}
	std::cout << "Type unknown: downcast from Base unsuccessful\n";
}
int main(void)
{
	std::srand(time(nullptr));

	for (int i = 1; i < 8; i++)
	{
		Base *base = generate();
		std::cout << "generated Base " << i << "\n";
		/*
		Supposedly, this is one of the normal ways to do it
		which is forbidden.
		*/
		// std::cout << "Type A (1 = true): " << (typeid(*base) == typeid(A)) << "\n";
		// std::cout << "Type name from typeinfo: " << typeid(*base).name() << "\n";
		
		identify(base);
		identify(*base);
		delete base;
		std::cout << "deleted Base\n\n";
	}

	return 0;
}
