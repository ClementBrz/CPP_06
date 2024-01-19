/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:59:14 by cbernaze          #+#    #+#             */
/*   Updated: 2024/01/19 15:30:05 by cbernaze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <stdint.h>

#define CLEAR "\033c"
#define RESET "\e[0m"
#define BOLD_RED "\e[1;31m"
#define GREEN "\e[0;38;5;112m"
#define BLUE "\e[0;36m"
#define ORANGE "\e[0;38;5;209m"

struct Data
{
	int	i;
};

class Serializer
{
	public:
		Serializer();
		Serializer(Serializer const& other);
		~Serializer();
		Serializer	&operator=(Serializer const& other);

		static uintptr_t	serialize(Data *ptr);
		static Data*		deserialize(uintptr_t raw);
};

