/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:48:55 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/20 23:33:18 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
# include <iostream>
# include <cstring>
# include <cstdlib>

/******************************************************************************/
/*   CLASSES                                                                  */
/******************************************************************************/
class Fixed {

private:
	int			_fixedPointValue;
	static int const	_octetSize = 8;

public:
	Fixed( void );
	Fixed( Fixed const & src );
	~Fixed( void );

	Fixed &			operator=( Fixed const & rhs );

	int			getRawBits( void ) const;
	void			setRawBits( int const raw );

};
