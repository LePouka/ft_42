/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:03:45 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/22 00:54:58 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
int	main( void ) {
	ClapTrap	a = ClapTrap( "Gerard" );

	std::cout << a << std:: endl << std::endl;

	for ( int i = 0; i < 4; i++ ) {

		a.attack( "nobody" );

		std::cout << a << std:: endl << std::endl;
	}

	for ( int i = 0; i < 4; i++ ) {

		a.beRepaired( 1 );

		std::cout << a << std:: endl << std::endl;
	}

	a.takeDamage( 3 );

	std::cout << a << std:: endl << std::endl;

	a.beRepaired( 2 );

	std::cout << a << std:: endl << std::endl;

	a.beRepaired( 10 );

	std::cout << a << std:: endl << std::endl;

	a.attack( "nobody" );
	a.beRepaired( 10 );
	a.setEnergyPoints( 2 );
	a.takeDamage( BEAUCOUP );

	std::cout << std::endl << a << std:: endl << std::endl;

	a.attack( "nobody" );
	a.beRepaired( 10 );
	a.takeDamage( MOINS );

	return 0;
}
