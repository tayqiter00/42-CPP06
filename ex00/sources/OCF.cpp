#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) { std::cout << "ScalarConverter default constructor called\n"; }

ScalarConverter::ScalarConverter(ScalarConverter &scalar)
{
	*this = scalar;
	std::cout << "ScalarConverter copy constructor called\n";
}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter &scalar)
{
	if (this != &scalar)
		std::cout << "ScalarConverter copy assignment operator called\n";
	return (*this);
}

ScalarConverter::~ScalarConverter(void) { std::cout << "ScalarConverter destructor called\n"; }
