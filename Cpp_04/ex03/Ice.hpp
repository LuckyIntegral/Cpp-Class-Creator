
#pragma once

#ifndef ICE_HPP
# define ICE_HPP


# include <string>

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Ice : public AMateria {
public:
    Ice( void );
    Ice( const Ice &other );
	Ice( std::string const &type );
    ~Ice();

	AMateria    *clone( void ) const;
	void        use( ICharacter &target );

    Ice    &operator=( const Ice &other );
};


#endif // ICE_HPP
