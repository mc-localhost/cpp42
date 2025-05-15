#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	private:
		std::string *_ideas;
	public:
		// Constructors
		Brain();
		Brain(const Brain &copy);
		
		// Destructor
		virtual ~Brain();
		
		// Operators
		Brain & operator=(Brain assign);
		
		void addFirstIdea(std::string idea);
		void printFirstIdea() const;

};

#endif