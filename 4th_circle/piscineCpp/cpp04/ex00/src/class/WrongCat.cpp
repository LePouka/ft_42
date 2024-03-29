/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:51:53 by rtissera          #+#    #+#             */
/*   Updated: 2024/03/02 17:39:55 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include "WrongCat.hpp"

/******************************************************************************/
/*   CONSTRUCTORS / DESTRUCTORS                                               */
/******************************************************************************/
WrongCat::WrongCat( void ) : WrongAnimal( "Wrong cat" ) {

	std::cout << _type << ": default constructor called." << std::endl;
}

WrongCat::WrongCat( WrongCat const & src ) : WrongAnimal( src ) {

	std::cout << _type << ": copy constructor called." << std::endl;

	_type = src._type;
}

WrongCat::~WrongCat( void ) {

	std::cout << _type << ": default destructor called." << std::endl;
}

/******************************************************************************/
/*   ASSIGNATION OPERATOR                                                     */
/******************************************************************************/
WrongCat&	WrongCat::operator=( WrongCat const & rhs ) {

	if ( this != &rhs ) {

		_type = rhs._type;
	}

	return *this;
}

/******************************************************************************/
/*   FUNCTIONS                                                                */
/******************************************************************************/
void	WrongCat::makeSound( void ) const {

	std::cout << _type << ": meow !" << std::endl;
}
