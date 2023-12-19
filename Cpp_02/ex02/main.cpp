/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:54:22 by vfrants           #+#    #+#             */
/*   Updated: 2023/12/19 22:42:59 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	std::cout << "Test 1" << std::endl;
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	std::cout << "Test 2" << std::endl;
	{
		Fixed a(5);
		Fixed b(7);

		std::cout << "Begin: a = " << a << ", b = " << b << std::endl;

		std::cout << "Res a++: " << a++ << std::endl;
		std::cout << "Res a: " << a << std::endl;
		std::cout << "Res ++a: " << ++a << std::endl;
		std::cout << "Res (a > b): " << (a > b) << std::endl;
		std::cout << "Res (a < b): " << (a < b) << std::endl;
		std::cout << "Res (a == b): " << (a == b) << std::endl;
		std::cout << "Res (a != b): " << (a != b) << std::endl;
		std::cout << "Res b = b - 3: " << (b = b - 3) << std::endl;
		std::cout << "Res (a >= b): " << (a >= b) << std::endl;
		std::cout << "Res (a <= b): " << (a <= b) << std::endl;
		std::cout << "Res (a == b): " << (a == b) << std::endl;
		std::cout << "Res (a != b): " << (a != b) << std::endl;
		std::cout << "Res (a > b): " << (a > b) << std::endl;
		std::cout << "Res (a < b): " << (a < b) << std::endl;
		std::cout << "Res (a * b): " << (a * b) << std::endl;
		std::cout << "Res (a / b): " << (a / b) << std::endl;
		std::cout << "Res (a + b): " << (a + b) << std::endl;
		std::cout << "Res (a - b): " << (a - b) << std::endl;
	}
	return 0;
}