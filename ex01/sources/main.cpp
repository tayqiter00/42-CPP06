/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:31:20 by qtay              #+#    #+#             */
/*   Updated: 2024/11/13 23:59:15 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include <iostream>

/**
 * The reinterpret_cast allows you to convert any pointer type to any other
 * pointer type. But it is dangerous and doesn't perform safety checks.
 * 
 * We use uintptr_t because its size is guaranteed to be able to store a
 * pointer without loss of information
 * 
 * [ PDF REQUIREMENT ]
 * Use serialize() on the address of the Data object and pass its return value
 * to deserialize(). Then, ensure the return value of deserialize() compares
 * equal to the original pointer
 */
int	main()
{
	Data data1;
	uintptr_t	saved;
	// Serializer	test; // proof that it cannot be instantiated

	data1._dummyStr = "random string";
	saved = Serializer::serialize(&data1);
	if (Serializer::deserialize(saved) == &data1)
		std::cout << "SUCCESS!\n";
	else
		std::cout << "FAILURE!\n";
	return (0);
}
