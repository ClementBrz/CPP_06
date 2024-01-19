/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:19:32 by cbernaze          #+#    #+#             */
/*   Updated: 2024/01/19 15:31:12 by cbernaze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	struct Data	data;

	data.i = 42;

	std::cout << GREEN << &data.i << RESET << std::endl;
	std::cout << GREEN << Serializer::deserialize(Serializer::serialize(&data)) << RESET << std::endl;
}