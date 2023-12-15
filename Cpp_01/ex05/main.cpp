/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:47:06 by vfrants           #+#    #+#             */
/*   Updated: 2023/12/15 21:54:54 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main( int argc, char **argv )
{
	if (argc != 2)
	{
		std::cout << "usage: ./harl <level>" << std::endl;
		std::cout << "list of levels: DEBUG INFO WARNING ERROR" << std::endl;
	}
	return (0);
}