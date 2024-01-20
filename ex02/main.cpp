/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:24:56 by cbernaze          #+#    #+#             */
/*   Updated: 2024/01/20 11:09:33 by cbernaze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

#define CLEAR "\033c"
#define RESET "\e[0m"
#define BOLD_RED "\e[1;31m"
#define GREEN "\e[0;38;5;112m"
#define BLUE "\e[0;36m"
#define ORANGE "\e[0;38;5;209m"

class Base
{
	public:
		virtual	~Base();
};

class A: public Base {};
class B: public Base {};
class C: public Base {};

Base::~Base(){}

Base*	generate(void)
{
	int	randomNb = std::rand() % 3;

	switch (randomNb)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return NULL;
	}
}

void	identify(Base* p)
{
	char	type = dynamic_cast<A*>(p) ? 'A' : dynamic_cast<B*>(p) ? 'B' : 'C';
	std::cout	<< "Type: " << type << std::endl;
}

void	identify(Base& p)
{
	Base	tmp;

	try
	{
		tmp = dynamic_cast<A&>(p);
		std::cout << "Type: A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			tmp = dynamic_cast<B&>(p);
			std::cout << "Type: B" << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "Type: C" << std::endl;
		}
	}
}

int	main()
{
	std::srand(static_cast<unsigned int>(std::time(0)));

	Base	*b1 = generate();
	Base	*b2 = generate();
	Base	*b3 = generate();

	std::cout << CLEAR;
	std::cout << BLUE << "Identify with pointers:" << RESET << std::endl;
	std::cout  << std::endl;

	identify(b1);
	identify(b2);
	identify(b3);

	A	a;
	B	b;
	C	c;

	std::cout  << std::endl;
	std::cout << BLUE << "Identify with references:" << RESET << std::endl;
	std::cout  << std::endl;

	identify(&a);
	identify(&b);
	identify(&c);

	std::cout  << std::endl;

	delete b1;
	delete b2;
	delete b3;
}