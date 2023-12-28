
#pragma once

#ifndef CURE_HPP
# define CURE_HPP


# include <string>

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Cure : public AMateria {
public:
    Cure( void );
    Cure( const Cure &other );
	Cure( std::string const &type );
    ~Cure();

	AMateria    *clone( void ) const;
	void        use( ICharacter &target );

    Cure    &operator=( const Cure &other );
};


#endif // CURE_HPP
