/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:35:33 by cbernaze          #+#    #+#             */
/*   Updated: 2024/01/18 14:53:02 by cbernaze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <cctype>
#include <cstdlib>
#include <iostream>

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

