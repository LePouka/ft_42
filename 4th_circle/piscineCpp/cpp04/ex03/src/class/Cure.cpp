/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:05:32 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/23 18:10:49 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include "Cure.hpp"

/******************************************************************************/
/*   CONSTRUCTORS / DESTRUCTORS                                               */
/******************************************************************************/
Cure::Cure( void ) : _type( "cure" ) {}

Cure::Cure( Cure const & src ) : _type( src._type ) {}

Cure::~Cure( void ) {}

/******************************************************************************/
/*   ASSIGNATION OPERATOR                                                     */
/******************************************************************************/
Cure&	Cure::operator=( Cure const & rhs ) {

	if ( this != &rhs ) {

		_type = rhs._type;
	}

	return *this;
}

/******************************************************************************/
/*   FUNCTIONS                                                                */
/******************************************************************************/
AMateria*	clone( void ) const {}

void	use( ICharacter& taget ) {}
