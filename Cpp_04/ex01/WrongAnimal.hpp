/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:51:21 by vfrants           #+#    #+#             */
/*   Updated: 2023/12/23 17:58:40 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP


# include <string>

class WrongAnimal {
protected:
    std::string _type;
public:
    WrongAnimal();
    WrongAnimal( const WrongAnimal &other );
    ~WrongAnimal();

    void    makeSound( void ) const;

    void            setType( std::string name );
    std::string     getType( ) const;

    WrongAnimal    &operator=( const WrongAnimal &other );
};


#endif // WRONG_ANIMAL_HPP
