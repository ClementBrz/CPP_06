/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:36:00 by cbernaze          #+#    #+#             */
/*   Updated: 2024/01/17 19:14:33 by cbernaze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

//******************************************************************//
//						CONSTRUCTEUR & DESTRUCTEUR					//
//******************************************************************//


ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const& other) {*this = other;}

ScalarConverter::~ScalarConverter() {}


//******************************************************************//
//								AUTRES								//
//******************************************************************//

static bool	isLiteralChar(std::string const literal)
{
	return (literal.length() == 1 && std::isprint(literal[0]));
}

static bool	isLiteralInt(std::string const literal)
{
	for (size_t i = 0; i < literal.length(); i++)
	{
		if (i == 0 && literal[i] == '-')
			i++;
		else if (!std::isdigit(literal[i]))
			return false;
	}
	return true;
}

// static bool	isLiteralFloat(std::string const literal)
// {

// }

// static bool	isLiteralDouble(std::string const literal)
// {

// }

static bool	checkType(std::string const literal)
{
	if (isLiteralChar(literal))
		return true;
	else if (isLiteralInt(literal))
		return true;
	// else if (isLiteralFloat(literal))
	// 	return true;
	// else if (isLiteralDouble(literal))
		// return true;
	return false;
}


//******************************************************************//
//						METHODES & FONCTIONS MEMBRES				//
//******************************************************************//


void	ScalarConverter::convert(std::string literal)
{
	try
	{
		if (!checkType(literal))
			throw std::string("Invalid type.");
		else
		{
			std::cout << literal << std::endl;
		}
	}
	catch (std::string const& str)
	{
		std::cerr << str << std::endl;
	}
}


//******************************************************************//
//							  EXCEPTIONS							//
//******************************************************************//


//******************************************************************//
//						SURCHARGES D'OPERATEURS						//
//******************************************************************//

ScalarConverter&	ScalarConverter::operator=(ScalarConverter const& other)
{
	static_cast<void>(other);

	return *this;
}