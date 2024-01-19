/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:58:58 by cbernaze          #+#    #+#             */
/*   Updated: 2024/01/19 15:30:19 by cbernaze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){}
Serializer::Serializer(Serializer const& other){*this = other;}
Serializer::~Serializer(){}
Serializer	&Serializer::operator=(Serializer const& other){
	static_cast<void>(other);
	return *this;
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(&(ptr->i));
}


Data*	Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}