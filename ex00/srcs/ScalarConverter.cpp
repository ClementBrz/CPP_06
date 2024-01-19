/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:36:00 by cbernaze          #+#    #+#             */
/*   Updated: 2024/01/19 14:51:57 by cbernaze         ###   ########.fr       */
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

static bool	isSpecial(std::string const literal)
{
	if (literal == "nan" || literal == "+inf" || literal == "-inf"
		|| literal == "nanf" || literal == "+inff" || literal == "-inff")
		return true;
	return false;
}

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
	if (isSpecial(literal))
		return "special";
	else if (isLiteralChar(literal))
		return "char";
	else if (isLiteralInt(literal))
		return "int";
	else if (isLiteralFloat(literal))
		return "float";
	else if (isLiteralDouble(literal))
		return "double";
	return "invalid";
}

static void	charConvert(char c)
{
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

static void	checkTypesLimits(long double ld, t_num *nums)
{
	if (ld >= std::numeric_limits<char>::min() && ld <= std::numeric_limits<char>::max())
		nums->limitsChar = true;
	else
		nums->limitsChar = false;
	if (ld >= std::numeric_limits<int>::min() && ld <= std::numeric_limits<int>::max())
		nums->limitsInt = true;
	else
		nums->limitsInt = false;
	if (ld >= std::numeric_limits<float>::min() && ld <= std::numeric_limits<float>::max())
		nums->limitsFloat = true;
	else
		nums->limitsFloat = false;
	if (ld >= std::numeric_limits<double>::min() && ld <= std::numeric_limits<float>::max())
		nums->limitsDouble = true;
	else
		nums->limitsDouble = false;
}

static void	numConvert(std::string literal, std::string type)
{
	t_num		nums;
	char		*ptr = NULL;
	long double	ld = std::strtold(literal.c_str(), &ptr);

	checkTypesLimits(ld, &nums);

	if (type == "int")
	{
		if (nums.limitsInt)
		{
			int	i = std::atoi(literal.c_str());
			if (nums.limitsChar && std::isprint(i))
				std::cout << "char: " << static_cast<char>(i) << std::endl;
			else
				std::cout << "char: impossible" << std::endl;
			std::cout << "int: " << i << std::endl;
			std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
			std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
		}
		else
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
		}
	}
	else if (type == "float")
	{
		if (nums.limitsFloat)
		{
			float	f = std::strtof(literal.c_str(), &ptr);
			if (nums.limitsChar && std::isprint(static_cast<int>(f)))
				std::cout << "char: " << static_cast<char>(f) << std::endl;
			else
				std::cout << "char: impossible" << std::endl;
			if (nums.limitsInt)
				std::cout << "int: " << static_cast<int>(f) << std::endl;
			else
				std::cout << "int: impossible" << std::endl;
			std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
			std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(f) << std::endl;
		}
		else
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
		}
	}
	else if (type == "double")
	{
		if (nums.limitsDouble)
		{
			double	d = std::strtod(literal.c_str(), &ptr);
			if (nums.limitsChar && std::isprint(static_cast<int>(d)))
				std::cout << "char: " << static_cast<char>(d) << std::endl;
			else
				std::cout << "char: impossible" << std::endl;
			if (nums.limitsInt)
				std::cout << "int: " << static_cast<int>(d) << std::endl;
			else
				std::cout << "int: impossible" << std::endl;
			if (nums.limitsFloat)
				std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(d) << "f" << std::endl;
			else
				std::cout << "float: impossible" << std::endl;
			std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
		}
		else
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
		}
	}
}

static void	special(std::string const literal)
{
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << literal << "f" << std::endl;
		std::cout << "double: " << literal << std::endl;
	}
	else if (literal == "nanf" || literal == "+inff" || literal == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << literal << std::endl;
		if (literal == "nanf")
			std::cout << "double: " << literal.substr(0,3) << std::endl;
		else
			std::cout << "double: " << literal.substr(0,4) << std::endl;
	}
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
			if (type == "special")
				special(literal);
			if (type == "char")
				charConvert(literal[0]);
			else
				numConvert(literal, type);
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