/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatesho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:45:16 by dmatesho          #+#    #+#             */
/*   Updated: 2020/02/28 21:25:24 by dmatesho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_wdct(char const *s, char c)
{
	int words;

	words = 0;
	while (*s == c)
		s++;
	while (*s)
	{
		if (*s == c)
		{
			while (*s == c)
				s++;
			words++;
		}
		s++;
	}
	return (words);
}

static int	ft_wdln(char const *s, char c)
{
	int len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		j;

	if (!(ptr = (char **)malloc(sizeof(char *) * (ft_wdct(s, c) + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			j = 0;
			if (!(ptr[i] = (char *)malloc(sizeof(char) * (ft_wdln(s, c) + 1))))
				return (NULL);
			while (*s != c && *s)
				ptr[i][j++] = (char)*s++;
			ptr[i][j] = '\0';
			i++;
		}
	}
	ptr[i] = NULL;
	return (ptr);
}
