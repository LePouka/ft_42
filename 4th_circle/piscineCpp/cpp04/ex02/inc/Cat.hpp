/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:38:42 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/23 19:13:45 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include "AAnimal.hpp"

/******************************************************************************/
/*   CLASSES                                                                  */
/******************************************************************************/
class Cat : public AAnimal {

private:
	Brain*	_brain;

public:
	Cat( void );
	Cat( Cat const & src );
	virtual ~Cat( void );

	Cat&	operator=( Cat const & rhs );

	void	makeSound( void ) const;
	void	printIdeas( void ) const;
};
