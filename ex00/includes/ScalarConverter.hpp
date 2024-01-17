/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:35:33 by cbernaze          #+#    #+#             */
/*   Updated: 2024/01/17 19:15:11 by cbernaze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cctype>
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

