/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:29:56 by rtissera          #+#    #+#             */
/*   Updated: 2022/11/26 17:09:35 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	size2;
	size_t	size3;

	i = 0;
	j = 0;
	if (!size && (!dst || !src))
		return (0);
	size3 = ft_strlen(src);
	while (dst[j] && j < size)
		j++;
	size2 = j;
	if (size == 0 || size <= size2)
		return (size3 + size);
	while ((src[i]) && ((size - size2 - 1) > i))
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (size2 + size3);
}
