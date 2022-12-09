/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:04:49 by rtissera          #+#    #+#             */
/*   Updated: 2022/12/09 14:07:04 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int	ft_putu(unsigned int n)
{
	int					i;
	long long int	nb;
	char				c;

	nb = n;
	c = 0;
	if (nb < 10)
	{
		c = nb + 48;
		i += ft_putchar(c);
	}
	if (nb >= 10)
	{
		ft_putnbr_base((nb / 10), 10, "0123456789");
		ft_putnbr_base((nb % 10), 10, "0123456789");
	}
}
