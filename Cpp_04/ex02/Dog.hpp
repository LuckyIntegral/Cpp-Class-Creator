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
#include "Brain.hpp"

#define TYPE_DOG "Dog"

class Dog : public Animal {
private:
    Brain *_brain;
public:
    Dog( void );
    Dog( const Dog &other );
    virtual ~Dog();

    virtual void makeSound( void ) const;
    void    announceIdea( void ) const;

    Dog &operator=( const Dog &other );
};


#endif
