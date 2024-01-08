/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urmom <urmom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:34:36 by urmom             #+#    #+#             */
/*   Updated: 2024/01/08 14:34:36 by urmom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef HELLO_HPP
# define HELLO_HPP


# include <string>

# define DEFAULT_HELLO

class hello {
protected:
	std::string	_hello;

public:
	hello();
	hello( std::string hello );
	hello( const hello &other );
	~hello();

	std::string	getHello( void ) const;
	void		setHello( const std::string hello );

	hello &operator=( const hello &other );
};

std::ostream	&operator<<( std::ostream &stream, const hello &instance );


#endif // HELLO_HPP
