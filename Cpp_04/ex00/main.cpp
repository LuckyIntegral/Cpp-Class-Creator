/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 01:13:31 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/02 19:20:02 by vfrants          ###   ########.fr       */
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
        const Animal *cat = new Dog();
        const Animal *dog = new Cat();

        std::cout << cat->getType() << std::endl;
        std::cout << dog->getType() << std::endl;

        dog->makeSound();
        cat->makeSound(); //will output the cat sound!
        meta->makeSound();

        delete dog;
        delete cat;
        delete meta;
    }
    std::cout << "\nTest 2\n" << std::endl;
    {
        const WrongAnimal *meta = new WrongAnimal();
        const WrongAnimal *cat = new WrongCat();

        std::cout << cat->getType() << std::endl;

        meta->makeSound();
        cat->makeSound(); //will output the cat sound!

        delete cat;
        delete meta;
    }

    return (0);
}
