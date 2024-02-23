/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:44:13 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/23 20:06:22 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include "Animal.hpp"

/******************************************************************************/
/*   CLASSES                                                                  */
/******************************************************************************/
class Dog : public Animal {

private:
	Brain*	_brain;

public:
	Dog( void );
	Dog( Dog const & src );
	~Dog( void );

	Dog&	operator=( Dog const & rhs);

	void	makeSound( void ) const;
	void	printIdeas( void ) const;
};
