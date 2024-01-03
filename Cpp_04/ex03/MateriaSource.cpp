
#include <iostream>

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) {
    // std::cout << "MateriaSource: default constructor has been called" << std::endl;
	for (int i = 0; i < 4; ++i)
		this->_array[i] = NULL;
}

MateriaSource::MateriaSource( const MateriaSource &other ) {
    // std::cout << "MateriaSource: copy constructor has been called" << std::endl;
    *this = other;
}

MateriaSource::~MateriaSource() {
    // std::cout << "MateriaSource: destructor has been called" << std::endl;
	for (int i = 0; i < 4; ++i)
		if (this->_array[i])
			delete this->_array[i];
}

void	MateriaSource::learnMateria( AMateria *toLearn ) {
	for (int i = 0; i < 4; ++i)
		if (this->_array[i] == NULL)
			this->_array[i] = toLearn, i = 4;
}

AMateria	*MateriaSource::createMateria( std::string const &type ) {
	for (int i = 0; i < 4; ++i)
		if (this->_array[i] && this->_array[i]->getType() == type)
			return (this->_array[i]->clone());
	return (NULL);
}

MateriaSource &MateriaSource::operator=( const MateriaSource &other ) {
    // std::cout << "MateriaSource: copy assignment operator has been called" << std::endl;
	for (int i = 0; i < 4; ++i)
		if (this->_array[i])
			delete this->_array[i];

	for (int i = 0; i < 4; ++i)
		if (other._array[i])
			this->_array[i] = other._array[i]->clone();
    return (*this);
}
