/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:34:53 by rtissera          #+#    #+#             */
/*   Updated: 2022/11/21 11:42:53 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*b;

	i = 0;
	b = (char *)big;
	if (little[i] == 0)
		return (b);
	while (b[i] && (i < len))
	{
		j = 0;
		while ((little[j] == big[i + j]) && (i + j < len))
		{
			j++;
			if (little[j] == '\0')
				return (b + i);
		}
		i++;
	}
	return (0);
}
