/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:07:41 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/06 17:47:00 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include <iostream>
#include <cstring>

/******************************************************************************/
/*   CLASSES                                                                  */
/******************************************************************************/
class Contact {

private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

public:
	Contact( void );
	~Contact( void );

	std::string	getFirstName( void ) const;
	std::string	getLastName( void ) const;
	std::string	getNickname( void ) const;
	std::string	getPhoneNumber( void ) const;
	std::string	getDarkestSecret( void ) const;

	void		setFirstName( std::string firstName );
	void		setLastName( std::string lastName );
	void		setNickname( std::string nickname );
	void		setPhoneNumber( std::string phoneNumber );
	void		setDarkestSecret( std::string darkestSecret );

	void		printName( std::string name) const ;
	void		printLineContact( void ) const;
	void		printRawContact( void ) const;

	static bool	checkName( std::string name );
	static bool	checkPrint( std::string str );
	static bool	checkNumber( std::string number );

};

#endif
