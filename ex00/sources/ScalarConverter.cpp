/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:43:37 by qtay              #+#    #+#             */
/*   Updated: 2025/02/06 12:10:49 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

static void	printChar(std::string const &toConvert)
{
	std::cout << "printChar\n";
	if (std::isprint(toConvert[0]))
		std::cout << "char: '" << toConvert[0] << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

    std::cout << "int: " << static_cast<int>(toConvert[0]) << std::endl;
    std::cout << "float: " << static_cast<float>(toConvert[0]) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(toConvert[0]) << ".0" << std::endl;
}

static void	printInt(std::string const &toConvert)
{
	int	val = ft_stoi(toConvert);

	std::cout << "printInt\n";
	if (val >= 32 && val <= 126)
    	std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
	else if (val >= -128 && val <= 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: Impossible" << std::endl;

    if (errno == ERANGE) // set by ft_stoi()
	{
		if (val == INT_MAX)
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

/**
 * strtof() cannot handle integers properly as floats only have 23 bits
 * of precision for the mantissa. Use strtod() to handle INT_MAX/MIN.
 */
static void	printFloat(std::string const &toConvert)
{
	std::stringstream ss;
	double	_temp = std::strtod(toConvert.c_str(), NULL);
	errno = 0;
	float	_f = std::strtof(toConvert.c_str(), NULL);
	double	_d = static_cast<double>(_f);
	char	_c = static_cast<char>(_f);

	std::cout << "printFloat\n";
	if (errno == ERANGE) // float over/underflows
	{
		if (_f == HUGE_VAL)
		{
			std::cout << "char: Impossible" << std::endl;
			std::cout << "int: Overflow\n";
			std::cout << "float: +inff (Overflow)\n";
			std::cout << "double: +inf (Overflow)\n";
		}
		else if (_f == -HUGE_VAL)
		{
			std::cout << "char: Impossible" << std::endl;
			std::cout << "int: Underflow\n";
			std::cout << "float: -inff (Overflow)\n";
			std::cout << "double: -inf (Overflow)\n";	
		}
		else
		{
			std::cout << "char: Non displayable" << std::endl;
			std::cout << "int: 0\n";
			std::cout << "float: 0.0f (Underflow)\n";
			std::cout << "double: 0.0 (Underflow)\n";	
		}
		return ;
	}

	{
		if (_temp >= 32 && _temp <= 126)
			std::cout << "char: '" << _c << "'" << std::endl;
		else if (_temp >= -128 && _temp <= 127)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: Impossible" << std::endl;
	}

	{
		if (_temp < (std::numeric_limits<int>::min()))
			std::cout << "int: Underflow\n";
		else if (_temp > (std::numeric_limits<int>::max()))
			std::cout << "int: Overflow\n";
		else
			std::cout << "int: " << static_cast<int>(_f) << std::endl;
	}

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
	float	_temp = std::strtof(toConvert.c_str(), NULL);
	int		savedErrno = errno;
	errno = 0;
	double	_d = std::strtod(toConvert.c_str(), NULL);
	float	_f = static_cast<float>(_d);
	char	_c = static_cast<unsigned char>(_d);

	std::cout << "printDouble\n";
	if (errno == ERANGE) // double over/underflows
	{
		if (_d == HUGE_VAL)
		{
			std::cout << "char: Impossible" << std::endl;
			std::cout << "int: Overflow\n";
			std::cout << "float: +inff (Overflow)\n";
			std::cout << "double: +inf (Overflow)\n";
		}
		else if (_d == -HUGE_VAL)
		{
			std::cout << "char: Impossible" << std::endl;
			std::cout << "int: Underflow\n";
			std::cout << "float: -inff (Overflow)\n";
			std::cout << "double: -inf (Overflow)\n";	
		}
		else
		{
			std::cout << "char: Non displayable" << std::endl;
			std::cout << "int: 0\n";
			std::cout << "float: 0.0f (Underflow)\n";
			std::cout << "double: 0.0 (Underflow)\n";	
		}
		return ;
	}

	{
		if (_d >= 32 && _d <= 126)
			std::cout << "char: '" << _c << "'" << std::endl;
		else if (_d >= -128 && _d <= 127)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: Impossible" << std::endl;
	}

	{
		if (_d < (std::numeric_limits<int>::min()))
			std::cout << "int: Underflow\n";
		else if (_d > (std::numeric_limits<int>::max()))
			std::cout << "int: Overflow\n";
		else
			std::cout << "int: " << static_cast<int>(_d) << std::endl;
	}
	
	if (savedErrno == ERANGE)
	{
		if (_temp == HUGE_VAL)
			std::cout << "float: +inff (Overflow)\n";
		else if (_temp == -HUGE_VAL)
			std::cout << "float: -inff (Overflow)\n";
		else
			std::cout << "float: 0.0f (Underflow)\n";
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
	std::cout << "printPseudoliteral\n";
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
		throw std::runtime_error("Not a valid type");
	}
}
