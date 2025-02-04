/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:10:59 by qtay              #+#    #+#             */
/*   Updated: 2025/02/04 17:16:54 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/ScalarConverter.hpp"
#include <string>
#include <cmath>

/**
 * A static member function belongs to the class itself, not to any specific
 * instance of the class. So it cannot access non-static member variables
 * or non-static member functions. It can be called using the class name
 * directly or through an object of the class (not here though since
 * ScalarConverter is an abstract class).
 */
int	main(int argc, char **argv)
{
	// if (argc == 1)
	// {
	// 	// [ SPECIAL TEST]
	// 	// {
	// 	// 	ScalarConverter::convert("nan");
	// 	// 	ScalarConverter::convert("nanf");
	// 	// 	ScalarConverter::convert("+inf");
	// 	// 	ScalarConverter::convert("+inff");
	// 	// 	ScalarConverter::convert("-inf");
	// 	// 	ScalarConverter::convert("-inff");
	// 	// }

	// 	// [ CHAR TEST ]
	// 	// Char: 0-31, 127-255: Nondisplayable; 32-126: Printable; Others: Impossible
	// 	// Int, Float and Double: All printable
	// 	// {
	// 	// 	for (int i = -5; i < 300; ++i)
	// 	// 	{
	// 	// 		ScalarConverter::convert(std::to_string(i));
	// 	// 		std::cout << "\n";
	// 	// 	}
	// 	// }
	// 	// std::cout << "Press any key to continue..." << std::endl;
	// 	// std::cin.get();

	// 	// // [ INT TEST ]
	// 	// // Char: 0-31, 127-255: Nondisplayable; 32-126: Printable; Others: Impossible
	// 	// // Int: Anything from -2147483648 to 2147483647. Others: Impossible (overflow)
	// 	// // Float and double: All printable but will return 0.0 or 0.0f if int overflows
	// 	{
	// 		for (int i = -10; i < 11; ++i)
	// 		{
	// 			ScalarConverter::convert(std::to_string(i));
	// 			std::cout << "\n";
	// 		}
	// 		ScalarConverter::convert(std::to_string(-123476));
	// 		std::cout << "\n";
	// 		ScalarConverter::convert(std::to_string(123476));
	// 		std::cout << "\n";
	// 		ScalarConverter::convert(std::to_string(0));
	// 		std::cout << "\n";
	// 		ScalarConverter::convert(std::to_string(-2147483648));
	// 		std::cout << "\n";
	// 		ScalarConverter::convert(std::to_string(2147483647));
	// 		std::cout << "\n";
	// 		ScalarConverter::convert(std::to_string(-2147483649));
	// 		std::cout << "\n";
	// 		ScalarConverter::convert(std::to_string(2147483648));
	// 		std::cout << "\n";
	// 	}
	// 	// std::cout << "Press any key to continue..." << std::endl;
	// 	// std::cin.get();

	// 	// [ FLOAT TEST ]
	// 	// Type casting removes the decimal places for int and char: equivalent to floor()

	// 	// Char: 0-31, 127-255: Nondisplayable; 32-126: Printable; Others: Impossible
	// 	// Int: Anything from -2147483648 to 2147483647. Others: Impossible (overflow)
	// 	// Float: -3.40282e+38 to 3.40282e+38. Others impossible (overflow)
	// 	// Double: All printable.
	// 	{
	// 		// for (float i = 1.0f; i < 1.1f; i = std::nextafter(i, 1.1f))
	// 		// {
	// 		// 	std::cout << "Actual float: " << i << "\n";
	// 		// 	ScalarConverter::convert(std::to_string(i));
	// 		// 	std::cout << "\n";
	// 		// }
	// 		// for (float i = -1.0f; i <= 2.0f; i += 0.1f)
	// 		// {
	// 		// 	ScalarConverter::convert(std::to_string(i));
	// 		// 	std::cout << "\n";
	// 		// }
	// 		// ScalarConverter::convert(std::to_string(__FLT_MAX__));
	// 		// std::cout << "\n";
	// 		// ScalarConverter::convert(std::to_string(__FLT_MAX__ * -1));
	// 	}

	// 	// [ DOUBLE TEST ]
	// 	// Type casting removes the decimal places for int and char: equivalent to floor()

	// 	// Char: 0-31, 127-255: Nondisplayable; 32-126: Printable; Others: Impossible
	// 	// Int: Anything from -2147483648 to 2147483647. Others: Impossible (overflow)
	// 	// Float: -3.40282e+38 to 3.40282e+38. Others impossible (overflow)
	// 	// Double: -1.79769e+308 to 1.79769e+308
	// 	{
	// 		// for (double i = -2.0; i <= 2.0; i += 0.1)
	// 		// {
	// 		// 	ScalarConverter::convert(std::to_string(i));
	// 		// 	std::cout << "\n";
	// 		// }
	// 		// ScalarConverter::convert(std::to_string(__DBL_MAX__));
	// 		// std::cout << "\n";
	// 		// ScalarConverter::convert(std::to_string(__DBL_MAX__ * -1));
	// 	}
	// }

	// [ to test float and double overflow; can add -]
	// ./convert 34100000000000000000000000000000000000.0f 
	// ./convert -18000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0
	if (argc > 2)
	{
		std::cerr << "Invalid num of args!\n";
		return (1);
	}
	
	if (argc == 2)
	{
		// ScalarConverter test;
		ScalarConverter::convert(argv[1]);
	}

	return (0);
}
