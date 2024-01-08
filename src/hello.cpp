/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urmom <urmom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:34:36 by urmom             #+#    #+#             */
/*   Updated: 2024/01/08 14:34:36 by urmom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/hello.hpp"

#include <iostream>

hello::hello() : _hello(DEFAULT_HELLO) {}
hello::hello( std::string hello ) : _hello(hello) {}
hello::hello( const hello &other ) : _hello(other._hello) {}
hello::~hello() {}

std::string hello::getHello( void ) const {
	return (this->_hello);
}

void hello::setHello( const std::string hello ) {
	this->_hello = hello;
}

hello &hello::operator=( const hello &other ) {
	this->_hello = other._hello;
	return (*this);
}

std::ostream	&operator<<( std::ostream &stream, const hello &instance ) {
	stream << "{hello:"
		<< "hello=" << instance.getHello() << '}';
	return (stream);
}
