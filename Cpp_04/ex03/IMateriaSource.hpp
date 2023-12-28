/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:34:23 by vfrants           #+#    #+#             */
/*   Updated: 2023/12/28 13:45:41 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef I_MATERIA_SOURCE_HPP
# define I_MATERIA_SOURCE_HPP


# include <string>

# include "AMateria.hpp"

class IMateriaSource
{
public:
	virtual ~IMateriaSource() {}

	virtual void		learnMateria( AMateria* ) = 0;
	virtual AMateria	*createMateria( std::string const & type ) = 0;
};

#endif // I_MATERIA_SOURCE_HPP
