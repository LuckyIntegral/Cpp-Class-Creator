
#ifndef CHARACTER_HPP
# define CHARACTER_HPP


# include <string>

# include "AMateria.hpp"
# include "ICharacter.hpp"

# define DEFAULT_NAME "John Wick"

class Character : public ICharacter {
protected:
	std::string	_name;
	AMateria	*_array[4];
public:
    Character();
    Character( const std::string name );
    Character( const Character &other );
    ~Character();

	std::string const &getName() const;

	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);

    Character    &operator=( const Character &other );
};


#endif // CHARACTER_HPP
