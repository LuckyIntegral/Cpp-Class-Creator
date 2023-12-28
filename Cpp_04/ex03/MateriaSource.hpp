
#pragma once

#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP


# include <string>

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class IMateriaSource;

class MateriaSource : public IMateriaSource {
protected:
	AMateria	*_array[4];
public:
    MateriaSource( void );
    MateriaSource( const MateriaSource &other );
    ~MateriaSource();

	void		learnMateria( AMateria* );
	AMateria	*createMateria( std::string const & type );

    MateriaSource    &operator=( const MateriaSource &other );
};


#endif // MATERIA_SOURCE_HPP
