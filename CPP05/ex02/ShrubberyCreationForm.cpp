
#include "ShrubberyCreationForm.hpp"

#define RESET	"\e[0m"
#define RED		"\e[41m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", req_sign, req_exec), target("Random")
{
	std::cout << BLUE << "Default constructor called of Shrubbery Form" << RESET << std::endl;
}


ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : AForm("Shrubbery", req_sign, req_exec),	target(_target)
{
	std::cout << BLUE << "Fields constructor called of Shrubbery Form" << RESET << std::endl;
}


ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << YELLOW << "Destructor called of Shrubbery Form" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), target(copy.target)
{
	std::cout << "Copy constructor called of Shrubbery Form" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign)
{
	target = assign.target;
	std::cout << "Copy assignment operator called of Shrubbery Form" << std::endl;
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return target;
}

int ShrubberyCreationForm::action() const
{
	auto file = this->target + "_shrubbery";
	std::ofstream ofs(file);
	if (!ofs.is_open()){
		std::cerr << "Error opening file for writing" << std::endl;
		return 1;
	}
	ofs << std::endl << " _{\\ _{\\{\\/}/}/}__"
		<< std::endl << " {/{/\\}{/{/\\}(\\}{/\\} _"
		<< std::endl << " {/{/\\}{/{/\\}(_)\\}{/{/\\}  _"
		<< std::endl << " {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}"
		<< std::endl << " {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}"
		<< std::endl << " _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}"
		<< std::endl << " {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}"
		<< std::endl << " _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}"
		<< std::endl << " {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}"
		<< std::endl << " {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}"
		<< std::endl << " {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)"
		<< std::endl << " {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}"
		<< std::endl << " {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}"
		<< std::endl << " {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}"
		<< std::endl << " (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)"
		<< std::endl << " {/{/{\\{\\/}{/{\\{\\{\\(_)/}"
		<< std::endl << " {/{\\{\\{\\/}/}{\\{\\\\}/}"
		<< std::endl << "  {){/ {\\/}{\\/} \\}\\}"
		<< std::endl << "  (_)  \\.-'.-/"
		<< std::endl << " __...--- |'-.-'| --...__"
		<< std::endl << " _...--\"   .-'   |'-.-'|  ' -.  ""--..__"
		<< std::endl << " -\"    ' .  . '    |.'-._| '  . .  '   jro"
		<< std::endl << " .  '-  '    .--'  | '-.'|    .  '  . '"
		<< std::endl << " ' ..     |'-_.-|"
		<< std::endl << " .  '  .       _.-|-._ -|-._  .  '  ."
		<< std::endl << "  .'   |'- .-|   '."
		<< std::endl << " ..-'   ' .  '.   `-._.-�   .'  '  - ."
		<< std::endl << " .-' '        '-._______.-'     '  ."
		<< std::endl << " .      ~,"
		<< std::endl << " .       .   |\\   .    ' '-."
		<< std::endl << " ___________/  \\____________"
		<< std::endl << " /  Why is it, when you want \\"
		<< std::endl << " |  something, it is so damn   |"
		<< std::endl << " |    much work to get it?     |"
		<< std::endl << " \\___________________________/" << std::endl;
	return 0;
}

