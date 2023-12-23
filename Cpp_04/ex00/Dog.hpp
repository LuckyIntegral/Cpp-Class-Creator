/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:26:49 by vfrants           #+#    #+#             */
/*   Updated: 2023/12/23 12:26:58 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP


#include "Animal.hpp"

#define TYPE_DOG "Dog"

class Dog : public Animal {
public:
    Dog();
    Dog( const Dog &other );
    ~Dog();

    virtual void makeSound() const;

    Dog &operator=( const Dog &other );
};


#endif
