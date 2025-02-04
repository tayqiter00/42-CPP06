/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:30:10 by qtay              #+#    #+#             */
/*   Updated: 2024/11/14 00:40:18 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include <iostream>

Serializer::Serializer(void) { std::cout << "Serializer default constructor called\n"; };

Serializer::Serializer(Serializer &serializer)
{
	*this = serializer;
	std::cout << "Serializer copy constructor called\n";
}

Serializer	&Serializer::operator=(Serializer &serializer)
{
	if (this != &serializer)
		std::cout << "Serializer copy assignment operator called\n";
	return (*this);
}

Serializer::~Serializer(void) { std::cout << "Serializer destructor called\n"; };

uintptr_t Serializer::serialize(Data* data)
{
	return (reinterpret_cast<uintptr_t>(data));
}

Data	*Serializer::deserialize(uintptr_t addr)
{
	return (reinterpret_cast<Data *>(addr));	
}
