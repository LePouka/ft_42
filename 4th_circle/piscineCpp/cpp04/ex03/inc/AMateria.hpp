/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:05:17 by rtissera          #+#    #+#             */
/*   Updated: 2024/03/02 15:18:34 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

/******************************************************************************/
/*   CLASSES                                                                  */
/******************************************************************************/
class AMateria {

private:
	AMateria( void );

protected:
	std::string		_type;

public:
	AMateria( std::string const & type );
	AMateria( AMateria const & src );
	virtual ~AMateria( void );

	AMateria&		operator=( AMateria const & rhs );

	std::string const &	getType( void ) const;

	virtual AMateria*	clone( void ) const = 0;
	virtual void		use( ICharacter& target );

};


/******************************************************************************/
/*   ASSIGNATION OPERATOR                                                     */
/******************************************************************************/
std::ostream&		operator<<( std::ostream& o, AMateria const & rhs );
