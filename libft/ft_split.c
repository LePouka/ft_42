/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:05:21 by rtissera          #+#    #+#             */
/*   Updated: 2022/11/21 11:58:00 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	howmanyc(const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	while (s[i])
	{
		if (s[i] == c)
			j++;
		i++;
	}
	return (j);
}

size_t	getnextc(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && (s[i] != c))
		i++;
	return (i - 1);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	nextc;
	char	**s2;

	i = 0;
	j = 0;
	s2 = malloc(sizeof(char *) * (howmanyc(s, c) + 1));
	nextc = getnextc(s, c);
	while (nextc != '\0')
	{
		s2[i] = ft_substr(s, j, nextc);
		if (!s2[i])
			free(s2[i]);
		j += nextc + 2;
		nextc = getnextc((s + nextc), c);
		i++;
	}
	s2[i] = NULL;
	return (s2);
}
