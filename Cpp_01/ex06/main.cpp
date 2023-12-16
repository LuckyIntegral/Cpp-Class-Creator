/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:47:06 by vfrants           #+#    #+#             */
/*   Updated: 2023/12/16 17:10:00 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Harl.hpp"

int	main( int argc, char **argv )
{
	Harl	harl;
	if (argc != 2)
	{
		std::cout << "usage: ./harlFilter <level>" << std::endl;
		std::cout << "list of levels: DEBUG INFO WARNING ERROR" << std::endl;
		return (1);
	}
	std::string	str(argv[1]);
	harl.complain(str);
	return (0);
}