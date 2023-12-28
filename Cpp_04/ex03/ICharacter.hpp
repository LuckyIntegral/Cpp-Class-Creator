/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:35:02 by vfrants           #+#    #+#             */
/*   Updated: 2023/12/28 13:35:05 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef I_CHARACTER_HPP
# define I_CHARACTER_HPP


# include <string>

# include "AMateria.hpp"

class AMateria;

class ICharacter {
public:
	virtual ~ICharacter() {}

	virtual std::string const &getName() const = 0;

	virtual void equip(AMateria *m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter &target) = 0;
};

#endif // I_CHARACTER_HPP
