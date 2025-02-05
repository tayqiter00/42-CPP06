/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:10:59 by qtay              #+#    #+#             */
/*   Updated: 2025/02/05 20:36:43 by qtay             ###   ########.fr       */
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
	(void)argv;
	if (argc == 1)
	{
		/* [ SPECIAL TEST ] */
		// std::cout << "[ SPECIAL TEST ]\n";
		// {
		// 	ScalarConverter::convert("nan"); std::cout << std::endl;
		// 	ScalarConverter::convert("nanf"); std::cout << std::endl;
		// 	ScalarConverter::convert("+inf"); std::cout << std::endl;
		// 	ScalarConverter::convert("+inff"); std::cout << std::endl;
		// 	ScalarConverter::convert("-inf"); std::cout << std::endl;
		// 	ScalarConverter::convert("-inff"); std::cout << std::endl;
		// }

		/** 
		 * [ CHAR TEST ]
		 * 0-31, 127, others: Non displayable
		 * 32-126: Printable
		 * */
		// std::cout << "[ CHAR TEST ]\n";
		// {
		// 	std::stringstream	ss;
		// 	for (int i = 0; i < 128; ++i)
		// 	{
		// 		ss.str("");
		// 		ss.clear();
		// 		ss << static_cast<char>(i);
		// 		try
		// 		{
		// 			ScalarConverter::convert(ss.str());
		// 		}
		// 		catch(const std::exception& e)
		// 		{
		// 			std::cerr << e.what() << '\n';
		// 		}
		// 		std::cout << "\n";
		// 	}
		// }

		/**
		 * [ INT TEST ]
		 * CHAR - 0-31, 127: Nondisplayable; 32-126: Printable; Others: Impossible
		 * INT - Anything from -2147483648 to 2147483647. Others: Impossible (over/underflow)
		 * FLOAT/DOUBLE - All printable. If INT over/underflows, give +/-inf(f)
		 */
		// std::cout << "[ INT TEST ]\n";
		// {
		// 	// std::stringstream	ss;
		// 	// for (int i = -10; i < 11; ++i)
		// 	// {
		// 	// 	ss.str("");
		// 	// 	ss.clear();
		// 	// 	ss << i;
		// 	// 	ScalarConverter::convert(ss.str());
		// 	// 	std::cout << "\n";
		// 	// }
		// 	ScalarConverter::convert("-123476"); std::cout << "\n";
		// 	ScalarConverter::convert("123476");std::cout << "\n";
		// 	ScalarConverter::convert("0"); std::cout << "\n";
		// 	ScalarConverter::convert("-2147483648");std::cout << "\n";
		// 	ScalarConverter::convert("2147483647"); std::cout << "\n";
		// 	ScalarConverter::convert("-2147483649");std::cout << "\n";
		// 	ScalarConverter::convert("2147483648");std::cout << "\n";
		// }

		/**
		 * [ FLOAT TEST ]
		 * Type casting removes the decimal places for int and char: equivalent to floor()
		 * CHAR - 0-31, 127: Non displayable; 32-126: Printable; Others: Impossible
		 * INT - Anything from -2147483648 to 2147483647. Others: Over/Underflow
		 * FLOAT - -3.40282e+38 to 3.40282e+38. Others: -/+inff
		 * DOUBLE - All okay. If float overflows/underflows give -/+inf.
		 * */ 
		{
			std::stringstream ss;
			std::cout << std::endl;
			// for (float i = 1.0f; i < 1.1f; i += 0.00001f)
			// {
			// 	std::cout << "Actual float: " << i << "f\n";
			// 	ss.str("");
			// 	ss.clear();
			// 	ss << i;
			// 	ScalarConverter::convert(ss.str() + "f");
			// 	std::cout << "\n";
			// }
			// for (float i = -1.0f; i <= 2.0f; i += 0.1f)
			// {
			// 	std::cout << "Actual float: " << i << "f\n";
			// 	ss.str("");
			// 	ss.clear();
			// 	ss << i;
			// 	ScalarConverter::convert(ss.str() + "f");
			// 	std::cout << "\n";
			// }
			ScalarConverter::convert("-2147483649f");
			std::cout << "\n";
			ScalarConverter::convert("2147483648f");
			std::cout << "\n";
			ScalarConverter::convert("3.40282347e+38f");
			std::cout << "\n";
			ScalarConverter::convert("3.40282347e+38f");
			std::cout << "\n";
			ScalarConverter::convert("-3.40282347e+38f");
			std::cout << "\n";
			ScalarConverter::convert("1.7976931348623157e+308f");
			std::cout << "\n";
			ScalarConverter::convert("-1.7976931348623157e+308f");
		}

		// [ DOUBLE TEST ]
		// Type casting removes the decimal places for int and char: equivalent to floor()

		// Char: 0-31, 127-255: Nondisplayable; 32-126: Printable; Others: Impossible
		// Int: Anything from -2147483648 to 2147483647. Others: Impossible (overflow)
		// Float: -3.40282e+38 to 3.40282e+38. Others impossible (overflow)
		// Double: -1.79769e+308 to 1.79769e+308
		// {
			// for (double i = -2.0; i <= 2.0; i += 0.1)
			// {
			// 	ScalarConverter::convert(std::to_string(i));
			// 	std::cout << "\n";
			// }
			// ScalarConverter::convert(std::to_string(__DBL_MAX__));
			// std::cout << "\n";
			// ScalarConverter::convert(std::to_string(__DBL_MAX__ * -1));
		// }
	}

	// [ to test float and double overflow; can add -]
	// ./convert 34100000000000000000000000000000000000.0f 
	// ./convert -18000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0
	// if (argc > 2)
	// {
	// 	std::cerr << "Invalid num of args!\n";
	// 	return (1);
	// }
	
	// if (argc == 2)
	// {
	// 	// ScalarConverter test;
	// 	ScalarConverter::convert(argv[1]);
	// }

	return (0);
}
