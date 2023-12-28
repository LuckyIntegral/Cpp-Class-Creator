
#pragma once

#ifndef A_MATERIA_HPP
# define A_MATERIA_HPP


# include <string>

# include "ICharacter.hpp"

class ICharacter;

class AMateria {
protected:
	std::string _type;
public:
    AMateria( void );
    AMateria( const AMateria &other );
    AMateria( std::string const &type );
    virtual ~AMateria();

	std::string const &getType( void ) const;

	virtual AMateria* clone( void ) const = 0;
	virtual void use(ICharacter &target);

    AMateria    &operator=( const AMateria &other );
};


#endif // A_MATERIA_HPP
