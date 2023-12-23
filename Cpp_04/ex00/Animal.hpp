/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 01:10:45 by vfrants           #+#    #+#             */
/*   Updated: 2023/12/23 01:21:54 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP


# include <string>

# define DEFAULT_TYPE "Animal"

class Animal {
protected:
    std::string _type;
public:
    Animal( );
    Animal( const Animal &other );
    virtual ~Animal( );

    virtual void    makeSound( void ) const;

    void            setType( std::string name );
    std::string     getType( ) const;

    Animal  &operator=( const Animal &other );
};


#endif
