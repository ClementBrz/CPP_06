/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:07:12 by cbernaze          #+#    #+#             */
/*   Updated: 2024/01/17 18:13:03 by cbernaze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return 0;

	std::string	literal = static_cast<std::string>(argv[1]);
	ScalarConverter::convert(literal);
}
