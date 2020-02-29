/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatesho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:45:16 by dmatesho          #+#    #+#             */
/*   Updated: 2020/02/28 21:43:41 by dmatesho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	word_count(const char *s, char c)
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
/*
{
	int			i;

	i = 0;
	if (*s && *s != c)
	{
		s++;
		i++;
	}
	while (*s)
	{
		while (*s == c)
		{
			s++;
			if (*s != c && *s)
				i++;
		}
		s++;
	}
	return (i);
}
*/
static int		length(const char *s, char c)
{
	int i;

	i = 0;
	while (*s != c && *s)
	{
		i++;
		s++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**arr;
	size_t		i;
	int			j;

	j = 0;
	if (!(arr = (char**)malloc(sizeof(char*) * word_count(s, c) + 1)))
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		i = 0;
		if (*s != c && *s)
		{
			if (!(arr[j] = (char*)malloc(length(s, c) + 1)))
				return (NULL);
			while (*s && *s != c)
				arr[j][i++] = (char)*s++;
			arr[j][i] = '\0';
			j++;
		}
	}
	arr[j] = NULL;
	return (arr);
}

/*
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
	size_t	j;

	if (!(ptr = (char **)malloc(sizeof(char *) * (ft_wdct(s, c) + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		j = 0;
		if (*s && *s != c)
		{
			if (!(ptr[i] = (char *)malloc(sizeof(char) * (ft_wdln(s, c) + 1))))
				return (NULL);
			while (*s && *s != c)
				ptr[i][j++] = (char)*s++;
			ptr[i][j] = '\0';
			i++;
		}
	}
	ptr[i] = NULL;
	return (ptr);
}
*/
