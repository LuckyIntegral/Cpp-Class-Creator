/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 01:13:31 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/02 21:35:53 by vfrants          ###   ########.fr       */
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

        j->announceIdea();
        std::cout << std::endl;
        i->announceIdea();
        std::cout << std::endl;

        delete j;
        std::cout << std::endl;
        delete i;
    }
    std::cout << "\nTest 2\n" << std::endl;
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
    std::cout << "\nTest 3\n" << std::endl;
    {
        Animal *a = new Cat();
        std::cout << std::endl;

        a->announceIdea();
        a->makeSound();
        std::cout << std::endl;

        Animal *b = new Cat();
        std::cout << std::endl;

        *a = *b;
        std::cout << std::endl;

        b->announceIdea();
        b->makeSound();
        std::cout << std::endl;

        delete a;
        std::cout << std::endl;
        delete b;
    }
    std::cout << "\nTest 4\n" << std::endl;
    {
        Cat  a = Cat();
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