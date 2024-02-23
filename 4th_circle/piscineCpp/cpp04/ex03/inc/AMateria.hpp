/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:05:17 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/23 17:56:43 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include <iostream>

/******************************************************************************/
/*   CLASSES                                                                  */
/******************************************************************************/
class AMateria {

protected:
	std::string		_type;

public:
	AMateria( void );
	AMateria( std::string const & type );
	AMateria( AMateria const & src );
	virtual ~AMateria( void );

	AMateria&		operator=( AMateria const & rhs );

	std::string const &	getType( void ) const;

	virtual AMateria*	clone( void ) const = 0;
	virtual void		use( ICharacter& target );
};
