/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:10:59 by qtay              #+#    #+#             */
/*   Updated: 2025/02/06 12:01:54 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

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
		std::cout << "[ SPECIAL TEST ]\n";
		{
			try
			{
				ScalarConverter::convert("nan"); std::cout << std::endl;
				ScalarConverter::convert("nanf"); std::cout << std::endl;
				ScalarConverter::convert("+inf"); std::cout << std::endl;
				ScalarConverter::convert("+inff"); std::cout << std::endl;
				ScalarConverter::convert("-inf"); std::cout << std::endl;
				ScalarConverter::convert("-inff"); std::cout << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}

		/** 
		 * [ CHAR TEST ]
		 * -128-31, 127, others: Non displayable
		 * 32-126: Printable
		 * Note: Casting an int that's too large or too small to char will result
		 *       in overflow. E.g., 128 will overflow to -128.
		 * */
		std::cout << "[ CHAR TEST ]\n";
		{
			for (int i = -128; i < 128; ++i)
			{
				char c = static_cast<char>(i);
				std::string	str(1, c);
				try
				{
					ScalarConverter::convert(str);
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
				}
				std::cout << "\n";
			}
		}

		/**
		 * [ INT TEST ]
		 * CHAR - See above with the addition of 'Impossible' if out of range.
		 * INT - Anything from -2147483648 to 2147483647. Others: Over/Underflow
		 * FLOAT/DOUBLE - All printable. If INT over/underflows, give +/-inf(f)
		 */
		std::cout << "[ INT TEST ]\n";
		{
			try
			{
				// std::stringstream	ss;
				// for (int i = -10; i < 11; ++i)
				// {
				// 	ss.str("");
				// 	ss.clear();
				// 	ss << i;
				// 	ScalarConverter::convert(ss.str());
				// 	std::cout << "\n";
				// }
				ScalarConverter::convert("-123"); std::cout << "\n";
				ScalarConverter::convert("123");std::cout << "\n";
				ScalarConverter::convert("0"); std::cout << "\n";
				ScalarConverter::convert("-2147483648");std::cout << "\n";
				ScalarConverter::convert("2147483647"); std::cout << "\n";
				ScalarConverter::convert("-2147483649");std::cout << "\n";
				ScalarConverter::convert("2147483648");std::cout << "\n";
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}

		/**
		 * [ FLOAT TEST ]
		 * Type casting removes the decimal places for int and char: equivalent to floor()
		 * +-3.40282347e+38f; +-1.17549435e-38f
		 * */ 
		{
			std::cout << "[ FLOAT TEST ]\n";
			try
			{
				// std::stringstream ss;
				// std::cout << std::endl;
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
				ScalarConverter::convert("123.0f");
				std::cout << "\n";
				ScalarConverter::convert("-123.0f");
				std::cout << "\n";
				ScalarConverter::convert("0f");
				std::cout << "\n";
				ScalarConverter::convert("12367.223f");
				std::cout << "\n";
				ScalarConverter::convert("-12367.223f");
				std::cout << "\n";
				ScalarConverter::convert("1234567.0f");
				std::cout << "\n";
				ScalarConverter::convert("-1234567.0f");
				std::cout << "\n";
				ScalarConverter::convert("2147483648f");
				std::cout << "\n";
				ScalarConverter::convert("-2147483649f");
				std::cout << "\n";
				ScalarConverter::convert("3.40282347e+38f");
				std::cout << "\n";
				ScalarConverter::convert("-3.40282347e+38f");
				std::cout << "\n";
				ScalarConverter::convert("1.17549435e-38f");
				std::cout << "\n";
				ScalarConverter::convert("-1.17549435e-38f");
				std::cout << "\n";
				ScalarConverter::convert("3.40282347e+39f");
				std::cout << "\n";
				ScalarConverter::convert("-3.40282347e+39f");
				std::cout << "\n";
				ScalarConverter::convert("1.17549435e-39f");
				std::cout << "\n";
				ScalarConverter::convert("-1.17549435e-39f");
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			
		}

		/**
		 * [ DOUBLE TEST ]
		 * +-1.7976931348623157e+308; +-2.2250738585072014e-308
		 */
		std::cout << "[ DOUBLE TEST ]\n";
		{
			try
			{
				// std::stringstream	ss;
				// for (double i = -2.0; i <= 2.0; i += 0.1)
				// {
				// 	std::cout << "Actual double: " << i << "\n";
				// 	ss.str("");
				// 	ss.clear();
				// 	ss << i;
				// 	ScalarConverter::convert(ss.str());
				// 	std::cout << "\n";
				// }
				ScalarConverter::convert("123.0");
				std::cout << "\n";
				ScalarConverter::convert("-123.0");
				std::cout << "\n";
				ScalarConverter::convert("0.00");
				std::cout << "\n";
				ScalarConverter::convert("12367.223");
				std::cout << "\n";
				ScalarConverter::convert("-12367.223");
				std::cout << "\n";
				ScalarConverter::convert("1234567.0");
				std::cout << "\n";
				ScalarConverter::convert("-1234567.0");
				std::cout << "\n";
				ScalarConverter::convert("2147483648.0");
				std::cout << "\n";
				ScalarConverter::convert("-2147483649.0");
				std::cout << "\n";
				ScalarConverter::convert("3.40282347e+38");
				std::cout << "\n";
				ScalarConverter::convert("-3.40282347e+38");
				std::cout << "\n";
				ScalarConverter::convert("1.17549435e-38");
				std::cout << "\n";
				ScalarConverter::convert("-1.17549435e-38");
				std::cout << "\n";
				ScalarConverter::convert("3.40282347e+39");
				std::cout << "\n";
				ScalarConverter::convert("-3.40282347e+39");
				std::cout << "\n";
				ScalarConverter::convert("1.17549435e-39");
				std::cout << "\n";
				ScalarConverter::convert("-1.17549435e-39");
				std::cout << "\n";
				ScalarConverter::convert("1.7976931348623157e+308");
				std::cout << "\n";
				ScalarConverter::convert("-1.7976931348623157e+308");
				std::cout << "\n";
				ScalarConverter::convert("2.2250738585072014e-308");
				std::cout << "\n";
				ScalarConverter::convert("-2.2250738585072014e-308");
				std::cout << "\n";
				ScalarConverter::convert("1.7976931348623157e+309");
				std::cout << "\n";
				ScalarConverter::convert("-1.7976931348623157e+309");
				std::cout << "\n";
				ScalarConverter::convert("2.2250738585072014e-309");
				std::cout << "\n";
				ScalarConverter::convert("-2.2250738585072014e-309");
				std::cout << "\n";
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
	}

	if (argc > 2)
	{
		std::cerr << "Invalid num of args!\n";
		return (1);
	}
	
	if (argc == 2)
	{
		// ScalarConverter test; // cannot be instantiated
		try
		{
			ScalarConverter::convert(argv[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	return (0);
}
