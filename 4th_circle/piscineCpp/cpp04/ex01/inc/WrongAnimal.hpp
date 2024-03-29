/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:50:40 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/23 19:46:00 by rtissera         ###   ########.fr       */
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
class WrongAnimal {

protected:
	std::string	_type;

public:
	WrongAnimal( void );
	WrongAnimal( std::string type );
	WrongAnimal( WrongAnimal const & src );
	~WrongAnimal( void );

	WrongAnimal&	operator=( WrongAnimal const & rhs );

	std::string	getType( void ) const;

	void	makeSound( void ) const;
};

/******************************************************************************/
/*   REDIRECTION OPERATOR                                                     */
/******************************************************************************/
std::ostream&		operator<<( std::ostream& o, WrongAnimal const & rhs );
