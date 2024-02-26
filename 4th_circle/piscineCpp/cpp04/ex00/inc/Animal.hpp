/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 08:40:45 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/22 18:08:29 by rtissera         ###   ########.fr       */
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
class Animal {

protected:
	std::string	_type;

public:
	Animal( void );
	Animal( std::string type );
	Animal( Animal const & src );
	virtual ~Animal( void );

	Animal&		operator=( Animal const & rhs );

	std::string	getType( void ) const;

	virtual void	makeSound( void ) const;
};

/******************************************************************************/
/*   REDIRECTION OPERATOR                                                     */
/******************************************************************************/
std::ostream&		operator<<( std::ostream& o, Animal const & rhs );