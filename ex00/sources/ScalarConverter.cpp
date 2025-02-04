/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:43:37 by qtay              #+#    #+#             */
/*   Updated: 2025/02/04 18:20:57 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static bool	isPseudoliteral(std::string const &toConvert)
{
	if (!toConvert.compare("+inf") || !toConvert.compare("-inf") || !toConvert.compare("nan")
		|| !toConvert.compare("+inff") || !toConvert.compare("-inff") || !toConvert.compare("nanf"))
		return (true);
	return (false);
}
/**
 * If isChar() returns true, int, float and double guaranteed to be able to print
 */
static bool	isChar(std::string const &toConvert)
{
    return (toConvert.length() == 1
			&& !isdigit(toConvert[0])
			&& std::isprint(toConvert[0]));
}

/**
 * If isInt() returns true, that means no decimal places or exponents exist.
 * Overflow/Underflow not handled here.
 */
static bool isInt(const std::string &toConvert)
{
    if (toConvert.empty())
		return (false);

    size_t start = 0;
    if (toConvert[0] == '-' || toConvert[0] == '+') {
        if (toConvert.length() == 1)
			return (false); // Just a sign is not valid
        start = 1;
    }

    for (size_t i = start; i < toConvert.length(); ++i) {
        if (!std::isdigit(toConvert[i]))
			return (false);
    }

    return (true);
}

static bool	isDouble(const std::string &toConvert)
{
	size_t	i = 0;
	bool	hasDecimal = false;
	bool	hasExponent = false;
	bool	hasDigit = false;

	if (toConvert.empty())
		return (false);
	if (!toConvert.compare("-inf") || !toConvert.compare("+inf") || !toConvert.compare("nan"))
		return (true);
	if (toConvert[i] == '+' || toConvert[i] == '-')
		i++;
	for (; i < toConvert.length(); ++i)
	{
		if (std::isdigit(toConvert[i]))
			hasDigit = true;
		else if (toConvert[i] == '.')
		{
			if (hasDecimal) // multiple decimals
				return (false);
			hasDecimal = true;
		}
		else if (toConvert[i] == 'e' || toConvert[i] == 'E')
		{
			if (hasExponent || !hasDigit) // multiple exponents and no digit before exponent
				return (false);
			hasExponent = true;
			if (i + 1 < toConvert.length() && (toConvert[i + 1] == '+' || toConvert[i + 1] == '-'))
				i++;
			if (i + 1 >= toConvert.length() || !std::isdigit(toConvert[i + 1])) // no digit after exponent
				return (false);
		}
		else
			return (false);
	}
	return (hasDigit && (hasDecimal || hasExponent));
}

static bool	isFloat(const std::string &toConvert)
{
	size_t	i = 0;
	bool	hasDecimal = false;
	bool	hasExponent = false;
	bool	hasDigit = false;
	bool	hasTrailingF = false;

	if (toConvert.empty())
		return (false);
	if (!toConvert.compare("-inff") || !toConvert.compare("+inff") || !toConvert.compare("nanf"))
		return (true);
	if (toConvert[i] == '+' || toConvert[i] == '-')
		i++;
	for (; i < toConvert.length(); ++i)
	{
		if (std::isdigit(toConvert[i]))
			hasDigit = true;
		else if (toConvert[i] == '.')
		{
			if (hasDecimal) // multiple decimals
				return (false);
			hasDecimal = true;
		}
		else if (toConvert[i] == 'e' || toConvert[i] == 'E')
		{
			if (hasExponent || !hasDigit) // multiple exponents and no digit before exponent
				return (false);
			hasExponent = true;
			if (i + 1 < toConvert.length() && (toConvert[i + 1] == '+' || toConvert[i + 1] == '-'))
				i++;
			if (i + 1 >= toConvert.length() || !std::isdigit(toConvert[i + 1])) // no digit after exponent
				return (false);
		}
		else if ((toConvert[i] == 'f' || toConvert[i] == 'F') && i == toConvert.length() - 1)
			hasTrailingF = true;
		else
			return (false);
	}
	return (hasDigit && hasTrailingF);
}

int strToInt(const std::string& str)
{
	long	result = 0;
	int		sign = 1;
	size_t	i = 0;

	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}

	for (; i < str.length(); i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);  // won't happen but jz leave as it is

		int	digit = str[i] - '0';
		result = result * 10 + digit;
	}
	result = result * sign;
	if (result > INT_MAX || result < INT_MIN)
		return (0);
	return static_cast<int>(result);
}

static void	printChar(std::string const &toConvert)
{
    std::cout << "char: '" << toConvert[0] << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(toConvert[0]) << std::endl;
    std::cout << "float: " << static_cast<float>(toConvert[0]) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(toConvert[0]) << ".0" << std::endl;
}

static void	printInt(std::string const &toConvert)
{
	int	val = strToInt(toConvert);

	if (val >= 32 && val <= 126)
    	std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
	else if ((val > 0 && val <= 255) || (val == 0 && toConvert.length() == 1))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: Impossible" << std::endl;

    if (val == 0 && toConvert.length() != 1)
	{
		if (toConvert[0] != '-')
		{
			std::cout << "int: Overflow\n";
			std::cout << "float: +inff\n";
			std::cout << "double: +inf\n";
			return ;
		}
		std::cout << "int: Underflow\n";
		std::cout << "float: -inff\n";
		std::cout << "double: -inf\n";
		return ;
	}
	else
		std::cout << "int: " << static_cast<int>(val) << std::endl;
	if ((toConvert.length() == 7 && toConvert[0] != '-') || toConvert.length() > 7)
	{
		std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(val) << std::endl;
	}
	else
	{
		std::cout << "float: " << static_cast<float>(val) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(val) << ".0" << std::endl;
	}
}

static void	printFloat(std::string const &toConvert)
{
	std::stringstream ss;
	long	_l = std::strtol(toConvert.c_str(), NULL, 10);
	float	_f = std::strtof(toConvert.c_str(), NULL);
	double _d = static_cast<double>(_f);
	// double	_d = std::strtod(toConvert.c_str(), NULL);
	char	_c = static_cast<unsigned char>(_f);

	if (_f > 31 && _f < 127)
    	std::cout << "char: '" << _c << "'" << std::endl;
	else if (_f > -1 && _f < 256)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: Impossible" << std::endl;

    if (_l < (std::numeric_limits<int>::min()))
		std::cout << "int: Underflow\n";
	else if (_l > (std::numeric_limits<int>::max()))
   		std::cout << "int: Overflow\n";
	else
		std::cout << "int: " << static_cast<int>(_f) << std::endl;

	if (_f >= std::numeric_limits<float>::max() + 1 || _f <= -std::numeric_limits<float>::max() - 1 || _f == ERANGE)
	{
		if (toConvert[0] == '-')
		{
			std::cout << "float: -inff\n";
			std::cout << "double: -inf\n";
		}
		else
		{
			std::cout << "float: +inff\n";
			std::cout << "double: +inf\n";	
		}
	}
	else
	{
		ss << _f;
		std::string floatStr = ss.str();
		if (floatStr.find('.') != std::string::npos || floatStr.find('e') != std::string::npos)
		{
			std::cout << "float: " << _f << "f" << std::endl;
			std::cout << "double: " <<  _d << std::endl;
		}
		else
		{
			std::cout << "float: " << _f << ".0f" << std::endl;
			std::cout << "double: " <<  _d << ".0" << std::endl;
		}
	}
}

static void	printDouble(std::string const &toConvert)
{
	std::stringstream ss;
	double	_d = std::strtod(toConvert.c_str(), NULL);
	long	_l = std::strtol(toConvert.c_str(), NULL, 10);
	float	_f = static_cast<float>(_d);
	char	_c = static_cast<unsigned char>(_d);

	if (_d >= 32 && _d <= 126)
    	std::cout << "char: '" << _c << "'" << std::endl;
	else if (_d > -1 && _d < 256)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: Impossible" << std::endl;

    if (_l < (std::numeric_limits<int>::min()))
		std::cout << "int: Underflow\n";
	else if (_l > (std::numeric_limits<int>::max()))
   		std::cout << "int: Overflow\n";
	else
		std::cout << "int: " << static_cast<int>(_d) << std::endl;
	
	if (_d > std::numeric_limits<double>::max())
	{
   		std::cout << "float: Overflow\n";
		std::cout << "double: Overflow\n";
	}
	else if (_d < -std::numeric_limits<double>::max())
	{
   		std::cout << "float: Underflow\n";
		std::cout << "double: Underflow\n";
	}
	else if (_d > std::numeric_limits<float>::max() || _d < -std::numeric_limits<float>::max())
	{
		if (_d > std::numeric_limits<float>::max())
   			std::cout << "float: Overflow\n";
		else
			std::cout << "float: Underflow\n";
		if ((toConvert.length() == 7 && toConvert[0] != '-') || toConvert.length() > 7)
			std::cout << "double: " << _d << std::endl;
		else
			std::cout << "double: " <<  _d << ".0" << std::endl;
	}
	else
	{
		ss << _d;
		std::string doubleStr = ss.str();
		if (doubleStr.find('.') != std::string::npos || doubleStr.find('e') != std::string::npos)
		{
			std::cout << "float: " << _f << "f" << std::endl;
			std::cout << "double: " <<  _d << std::endl;
		}
		else
		{
			std::cout << "float: " << _f << ".0f" << std::endl;
			std::cout << "double: " <<  _d << ".0" << std::endl;
		}
	}
}

void	printPseudoliteral(std::string const &toConvert)
{
	std::cout << "char: Impossible" << std::endl;
	std::cout << "int: Impossible" << std::endl;

	if (!toConvert.compare("+inf") || !toConvert.compare("+inff"))
	{
		std::cout << "float: " << "+inff" << std::endl;
		std::cout << "double: " << "+inf" << std::endl;
	}
	else if (!toConvert.compare("-inf") || !toConvert.compare("-inff"))
	{
		std::cout << "float: " << "-inff" << std::endl;
		std::cout << "double: " << "-inf" << std::endl;
	}
	else
	{
		std::cout << "float: " << "nanf" << std::endl;
		std::cout << "double: " << "nan" << std::endl;
	}
}

static ScalarType	getType(std::string const &toConvert)
{
	if (isPseudoliteral(toConvert))
		return (PSEUDOLITERAL);
	else if (isChar(toConvert))
		return (CHAR);
	else if (isInt(toConvert))
		return (INT);
	else if (isDouble(toConvert))
		return (DOUBLE);
	else if (isFloat(toConvert))
		return (FLOAT);
	else
		return (ERROR);
}

void	ScalarConverter::convert(std::string const toConvert)
{
	switch (getType(toConvert))
	{
		
	case (PSEUDOLITERAL):
		printPseudoliteral(toConvert);
		break;
	case (CHAR):
		printChar(toConvert);
		break ;
	
	case (INT):
		printInt(toConvert);
		break ;

	case (DOUBLE):
		printDouble(toConvert);
			break ;

	case (FLOAT):
		printFloat(toConvert);
		break;
	default:
		std::cerr << "Not a valid type\n";
		exit(1);
	}
}