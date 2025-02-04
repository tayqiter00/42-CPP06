/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:49:09 by qtay              #+#    #+#             */
/*   Updated: 2024/11/14 01:52:53 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "../includes/Base.hpp"

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

int	main()
{
	Base	*base;

	base = generate();
	identify(base);
	identify(*base);

	delete base;

	return (0);
}
