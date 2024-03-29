/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:17:00 by rtissera          #+#    #+#             */
/*   Updated: 2024/03/02 17:29:57 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include "Character.hpp"

/******************************************************************************/
/*   CONSRUCTORS / DESTRUCTOR                                                 */
/******************************************************************************/
Character::Character( void ) : _name( "Gerard" ) {

	std::cout << "Character: default constructor called" << std::endl;

	for ( int i = 0; i < 4; i++ ) {

		_m[ i ] = NULL;
	}
}

Character::Character( std::string const & name ) : _name( name ) {

	std::cout << "Character: string constructor called" << std::endl;

	for ( int i = 0; i < 4; i++ ) {

		_m[ i ] = NULL;
	}
}

Character::Character( Character const & src ) { 
 
	std::cout << "Character: copy constructor called" << std::endl;

	_name = src._name;
	for ( int i = 0; i < 4; i++ ) {

		if ( src._m[ i ] ) {

			_m[ i ] = src._m[ i ]->clone();
		}
		else {

			_m[ i ] = NULL;
		}
	}
}

Character::~Character( void ) {

	std::cout << "Character: default destructor called" << std::endl;

	for ( int i = 0; i < 4; i++ ) {

		if ( _m[ i ] ) {

			delete _m[ i ];
		}
	}
}

/******************************************************************************/
/*   ASSIGNATION OPERATOR                                                     */
/******************************************************************************/
Character&	Character::operator=( Character const & rhs ) {

	if ( this != &rhs ) {

		_name = rhs._name;
		for ( int i = 0; i < 4; i++ ) {

			delete _m[ i ];
			if ( rhs._m[ i ] ) {

				_m[ i ] = rhs._m[ i ]->clone();
			}
			else {

				_m[ i ] = NULL;
			}
		}
	}

	return *this;
}

/******************************************************************************/
/*   ACCESSORS                                                                */
/******************************************************************************/
std::string const &	Character::getName( void ) const {

	return _name;
}

AMateria*	Character::getM( int idx ) const {

	if ( _m[ idx ] ) {

		return _m[ idx ];
	}
	else {

		return NULL;
	}
}

/******************************************************************************/
/*   FUNCTIONS                                                                */
/******************************************************************************/
void	Character::equip( AMateria* m ) {

	for ( int i = 0; i < 4; i++ ) {

		if ( !_m[ i ] ) {

			_m[ i ] = m;

			return ;
		}
	}
	delete m;
}

void	Character::unequip( int idx ) {

	if ( idx < 0 || idx > 3 ) {

		return ;
	}
	_m[ idx ] = NULL;
}

void	Character::use( int idx, ICharacter& target ) {

	if ( idx < 0 || idx > 3 ) {

		return ;
	}
	if ( _m[ idx ] ) {

		_m[ idx ]->use( target );
	}
}
