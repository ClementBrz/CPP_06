/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:35:33 by cbernaze          #+#    #+#             */
/*   Updated: 2024/01/19 14:31:15 by cbernaze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <limits>
#include <string>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>

typedef struct s_num
{
	bool	limitsChar;
	bool	limitsInt;
	bool	limitsFloat;
	bool	limitsDouble;
}				t_num;

class ScalarConverter
{
	//Constructeur & Destructeur
	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter const& other);
		~ScalarConverter();

	//Fonctions membres & Methodes
		static void	convert(std::string literal);

	//Exceptions

	//Surcharges d'operateur
		ScalarConverter&	operator=(ScalarConverter const& other);
};

