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

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <iostream>

int main()
{
    std::cout << "\nTest 1\n" << std::endl;
    {
        const Animal *j = new Dog();
        std::cout << std::endl;
        const Animal *i = new Cat();
        std::cout << std::endl;

        delete j;
        std::cout << std::endl;
        delete i;
    }
    std::cout << "\nTest 2\n" << std::endl;
    {
        Animal *c = new Cat();
        std::cout << std::endl;
        c->announceIdea();
        std::cout << std::endl;
        delete c;
    }
    std::cout << "\nTest 3\n" << std::endl;
    {
        const int   size = 10;
        Animal      *animals[size];

        for (int i = 0; i < size; ++i) {
            if (i % 2) {
                animals[i] = new Cat();
            }
            else {
                animals[i] = new Dog();
            }
            std::cout << std::endl;
        }

        for (int i = 0; i < size; ++i) {
            animals[i]->makeSound();
            animals[i]->announceIdea();
        }

        std::cout << std::endl;

        for (int i = 0; i < size; ++i) {
            delete (animals[i]);
            std::cout << std::endl;
        }
    }
    std::cout << "\nTest 4\n" << std::endl;
    {
        Animal *a = new Cat();

        a->announceIdea();
        a->makeSound();

        Animal *b = new Cat();

        *a = *b;

        b->announceIdea();
        b->makeSound();

        delete a;
        delete b;
    }
    return (0);
}