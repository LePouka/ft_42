/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:22:08 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/06 13:38:25 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) {}

Zombie::~Zombie() {}

std::string	Zombie::getName(void) const {

	return (this->_name);
}

void	Zombie::setName(std::string str) {}

void	Zombie::announce(void) {

	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
