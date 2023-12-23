/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 01:13:31 by vfrants           #+#    #+#             */
/*   Updated: 2023/12/23 01:18:30 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <iostream>

int main( )
{
    std::cout << "\nTest 1\n" << std::endl;
    {
        const Animal *meta = new Animal();
        const Animal *j = new Dog();
        const Animal *i = new Cat();

        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;

        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();

        delete meta;
        delete i;
        delete j;
    }
    std::cout << "\nTest 2\n" << std::endl;
    {
        const WrongAnimal *meta = new WrongAnimal();
        const WrongAnimal *i = new WrongCat();

        std::cout << i->getType() << " " << std::endl;

        i->makeSound(); //will output the cat sound!
        meta->makeSound();

        delete meta;
        delete i;
    }
    std::cout << "\nTest 3\n" << std::endl;
    {
        const WrongAnimal meta;
        const WrongAnimal i = WrongCat();

        std::cout << i.getType() << " " << std::endl;

        i.makeSound(); //will output the cat sound!
        meta.makeSound();
    }

    return (0);
}