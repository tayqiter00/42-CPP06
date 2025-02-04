/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:24:11 by qtay              #+#    #+#             */
/*   Updated: 2024/11/14 01:53:51 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include <cstdlib>
#include <iostream>

/**
 * Dynamic casting is mainly used for safe downcasting at run time
 * 		- Downcasting: Casting a base class pointer (or reference) to a
 * 		  derived class pointer (or reference).
 * 		- Upcasting: vice versa.
 * 
 * Must have one virtual function in the base class (source type must
 * be polymorphic).
 */
Base	*generate(void)
{
	char	arr[] = {'A', 'B', 'C'};
	srand(static_cast<unsigned int>(time(0)));
    int randomIndex = rand() % 3;

    switch (arr[randomIndex])
	{
        case 'A':
            return (new A());
            break;
        case 'B':
            return (new B());
            break;
        case 'C':
			return (new C());
			break;
	}
	return (NULL);
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "[*p]: p is of type A\n";
	else if (dynamic_cast<B *>(p))
		std::cout << "[*p]: p is of type B\n";
	else if (dynamic_cast<C *>(p))
		std::cout << "[*p]: p is of type C\n";
	else
		std::cerr << "Invalid type\n";
}


void identify(Base &p)
{
	try
	{
		A	&a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "[&p]: p is of type A\n";
	}
	catch (const std::exception& e)
	{
		try
		{
			B	&b = dynamic_cast<B &>(p);
			(void)b;
			std::cout << "[&p]: p is of type B\n";
		}
		catch (const std::exception& e)
		{
			try
			{
				C	&c = dynamic_cast<C &>(p);
				(void)c;
				std::cout << "[&p]: p is of type C\n";	
			}
			catch (const std::exception& e)
			{
				std::cerr << "Invalid type\n";
			}
		}
	}
}
