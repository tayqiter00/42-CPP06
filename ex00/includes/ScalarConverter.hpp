/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:22:09 by qtay              #+#    #+#             */
/*   Updated: 2025/02/05 15:39:53 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <climits>
#include <limits>
#include <cstdlib>
#include <cerrno>
#include <sstream>
#include <exception>

/**
 * A static member function:
 * 	1. is independent of any object of the class.
 * 	2. can be called even if no objects of the class exist.
 * 	3. can be used to determine how many objects of the class have been created.
 * 	4. has a scope inside the class and cannot access the current object pointer.
 * 
 * In general, float (4 bytes) is precise up to 7 decimal places and double up to
 * 15 (8 bytes).
 */
class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter &scalar);
		ScalarConverter	&operator=(ScalarConverter &scalar);
		~ScalarConverter();

	public:
		static void		convert(std::string toConvert);
};

enum	ScalarType
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDOLITERAL,
	ERROR
};

#endif
