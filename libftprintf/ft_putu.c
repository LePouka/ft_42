/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:04:49 by rtissera          #+#    #+#             */
/*   Updated: 2022/12/06 14:17:38 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "print.h"

int	ft_putu(unsigned int n)
{
	int					i;
	long unsigned int	nb;
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
		ft_putnbr_fd(nb / 10);
		ft_putnbr_fd(nb % 10);
	}
}
