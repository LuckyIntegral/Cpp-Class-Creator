/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urmom <urmom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:43:53 by urmom          #+#    #+#             */
/*   Updated: 2024/01/05 14:43:54 by urmom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/-u.hpp"

#include <iostream>

-u::-u() {}
-u::-u( const -u & ) {}
-u::~-u() {}\n
-u &-u::operator=( const -u & ) {
	return (*this);
}\n
std::ostream	&operator<<( std::ostream &stream, const -u & ) {
	stream << "{-u:{}}";
	return (stream);
}
