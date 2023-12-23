/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 21:48:58 by vfrants           #+#    #+#             */
/*   Updated: 2023/12/23 21:48:58 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP


# include <string>

class Brain {
private:
    std::string _ideas[100];
public:
    Brain();
    Brain( const Brain &other );
    ~Brain();

    std::string getRandomIdea( void ) const;

    Brain    &operator=( const Brain &other );
};


#endif // BRAIN_HPP

