/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:58:45 by vfrants           #+#    #+#             */
/*   Updated: 2023/12/23 18:02:31 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP


# include <string>

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
    WrongCat();
    WrongCat( const WrongCat &other );
    ~WrongCat();

    void    makeSound( void ) const;

    WrongCat    &operator=( const WrongCat &other );
};


#endif // WRONG_CAT_HPP

