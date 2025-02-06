/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 00:14:56 by qtay              #+#    #+#             */
/*   Updated: 2025/02/06 12:04:48 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

int ft_stoi(const std::string& str)
{
	long	result = 0;
	int		sign = 1;
	size_t	i = 0;
	errno = 0;

	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}

	while (str[i] >= '0' && str[i] <= '9')
	{
		int	digit = str[i] - '0';
		if (sign == 1 && (result > (INT_MAX - digit) / 10))
		{
			errno = ERANGE;
			return (INT_MAX);
		}
		if (sign == -1 && (-result < (INT_MIN + digit) / 10))
		{
			errno = ERANGE;
			return (INT_MIN);
		}
		result = result * 10 + digit;
		i++;
	}
	return (static_cast<int>(result * sign));
}

bool	isPseudoliteral(std::string const &toConvert)
{
	if (!toConvert.compare("+inf") || !toConvert.compare("-inf") || !toConvert.compare("nan")
		|| !toConvert.compare("+inff") || !toConvert.compare("-inff") || !toConvert.compare("nanf"))
		return (true);
	return (false);
}

/**
 * If isChar() returns true, int, float and double guaranteed to be able to print
 */
bool	isChar(std::string const &toConvert)
{
    return (toConvert.length() == 1 && !isdigit(toConvert[0]));
}

/**
 * If isInt() returns true, that means no decimal places or exponents exist.
 * Overflow/Underflow not handled here.
 */
bool	isInt(const std::string &toConvert)
{
	if (toConvert.empty())
		return (false);

	size_t start = 0;
	if (toConvert[0] == '-' || toConvert[0] == '+')
	{
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

bool	isDouble(const std::string &toConvert)
{
	size_t	i = 0;
	bool	hasDecimal = false;
	bool	hasExponent = false;
	bool	hasDigit = false;

	if (toConvert.empty())
		return (false);
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

bool	isFloat(const std::string &toConvert)
{
	size_t	i = 0;
	bool	hasDecimal = false;
	bool	hasExponent = false;
	bool	hasDigit = false;
	bool	hasTrailingF = false;

	if (toConvert.empty())
		return (false);
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

// int	main()
// {
// 	int	x = ft_stoi("2147483649");
// 	if (errno == ERANGE)
// 	{
// 		if (x == INT_MIN)
// 			std::cout << "Underflow\n";
// 		else
// 			std::cout << "Overflow\n";
// 	}
// 	else
// 		std::cout << x << "\n";
// }
