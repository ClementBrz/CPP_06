/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:36:00 by cbernaze          #+#    #+#             */
/*   Updated: 2024/01/18 17:12:50 by cbernaze         ###   ########.fr       */
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
	return (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]));
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

static bool	isLiteralFloat(std::string const literal)
{
	size_t	i = 0;

	if (literal[i] == '-')
		i++;
	while (i < literal.length() && std::isdigit(literal[i]))
		i++;
	if (i == literal.length() || literal[i] != '.')
		return false;
	size_t	decimals = ++i;
	while (i < literal.length() && std::isdigit(literal[i]))
		i++;
	if (i - decimals > 6)
		return false;
	else if (i == literal.length() || (literal[i] != 'f' && literal[i] != 'F'))
		return false;
	else if (++i != literal.length())
		return false;
	return true;
}

static bool	isLiteralDouble(std::string const literal)
{
	size_t	i = 0;

	if (literal == "-.f" || literal == ".f" || literal == "-.")
	if (literal[i] == '-')
		i++;
	while (i < literal.length() && std::isdigit(literal[i]))
		i++;
	if (i == literal.length() || literal[i] != '.')
		return false;
	size_t	decimals = ++i;
	while (i < literal.length() && std::isdigit(literal[i]))
		i++;
	if (i - decimals > 15)
		return false;
	else if (i != literal.length())
		return false;
	return true;
}

static std::string	checkType(std::string const literal)
{
	if (isLiteralChar(literal))
		return "char";
	else if (isLiteralInt(literal))
		return "int";
	else if (isLiteralFloat(literal))
		return "float";
	else if (isLiteralDouble(literal))
		return "double";
	return "invalid";
}

void	charConvert(char c)
{
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}
void	intConvert(int i)
{
	if (i > -1 && i < 256)
	{
		if (std::isprint(i))
			std::cout << "char: " << static_cast<char>(i) << std::endl;
		else
			std::cout << "char: non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}
void	floatConvert(float f)
{
	std::cout << "float: " << f << "f" << std::endl;
}
void	doubleConvert(double d)
{
	std::cout << "double: " << d << std::endl;
}

//******************************************************************//
//						METHODES & FONCTIONS MEMBRES				//
//******************************************************************//


void	ScalarConverter::convert(std::string literal)
{
	try
	{
		std::string	type = checkType(literal);
		if (type == "invalid")
			throw std::string("Invalid type.");
		else
		{
			std::string	types[] = {"char", "int", "float", "double"};
			char		*ptr = NULL;
			int			i = 0;

			while (i < 4)
			{
				if (types[i] == type)
					break;
				i++;
			}
			switch (i)
			{
				case 0:
					charConvert(literal[0]);
					break;

				case 1:
					intConvert(std::strtol(literal.c_str(), &ptr, 10));
					break;

				case 2:
					floatConvert(std::strtod(literal.c_str(), &ptr));
					break;

				case 3:
					doubleConvert(std::strtold(literal.c_str(), &ptr));
			}
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