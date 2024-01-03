/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 01:13:31 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/02 21:33:57 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <iostream>

int main( )
{
    {
        const Animal *j = new Dog();
        const Animal *i = new Cat();

		std::cout << std::endl;

        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;

		std::cout << std::endl;

        j->makeSound();
        i->makeSound();

		std::cout << std::endl;

        delete j;
        delete i;
    }
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    {
        Cat  a;
        std::cout << std::endl;
        {
            Cat b;
            std::cout << std::endl;
            b = a;
            std::cout << std::endl;
        }
    }
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    {
        Dog  a;
        std::cout << std::endl;
        {
            Dog b;
            std::cout << std::endl;
            b = a;
            std::cout << std::endl;
        }
    }

    return (0);
}
