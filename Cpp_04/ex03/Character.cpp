
#include <iostream>

#include "Character.hpp"

Character::Character() : _name(DEFAULT_NAME) {
    // std::cout << "Character: default constructor has been called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_array[i] = NULL;
}

Character::Character( const std::string name ) : _name(name) {
    // std::cout << "Character: constructor has been called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_array[i] = NULL;
}

Character::Character( const Character &other ) {
    // std::cout << "Character: copy constructor has been called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_array[i] = NULL;
    *this = other;
}

Character::~Character() {
    // std::cout << "Character: destructor has been called" << std::endl;
	for (int i = 0; i < 4; ++i)
		if (this->_array[i])
			delete this->_array[i];
}

std::string const &Character::getName() const {
	return (this->_name);
}

void Character::equip(AMateria *m) {
	for (int i = 0; i < 4; ++i)
		if (this->_array[i] == NULL)
			this->_array[i] = m, i = 4;
}

void Character::unequip(int idx) {
	if (idx < 4 && idx >= 0 && this->_array[idx])
		this->_array[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
	if (idx < 4 && idx >= 0 && this->_array[idx])
		this->_array[idx]->use(target);
}

Character &Character::operator=( const Character &other ) {
    // std::cout << "Character: copy assignment operator has been called" << std::endl;
	if (this != &other) {
		this->_name = other._name;

		for (int i = 0; i < 4; i++)
			if (this->_array[i])
				delete this->_array[i];

		for (int i = 0; i < 4; i++)
			if (other._array[i])
				this->_array[i] = other._array[i]->clone();
	}
    return (*this);
}
