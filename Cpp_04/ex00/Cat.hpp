/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:38:25 by vfrants           #+#    #+#             */
/*   Updated: 2023/12/23 12:40:34 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP


#include "Animal.hpp"

#define TYPE_CAT "Cat"

class Cat : public Animal {
public:
    Cat();
    Cat( const Cat &other );
    ~Cat();

    virtual void makeSound() const;

    Cat &operator=( const Cat &other );
};


#endif
