/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:46:46 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/10 18:43:41 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
# include <iostream>
# include <cstring>

/******************************************************************************/
/*   CLASSES                                                                  */
/******************************************************************************/
class Weapon {

private:
	std::string	_type;

public:
	Weapon( std::string type );
	~Weapon( void );

	std::string	getType( void ) const;

	void		setType( std::string type );

};

#endif
