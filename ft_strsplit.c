/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatesho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:07:56 by dmatesho          #+#    #+#             */
/*   Updated: 2020/02/25 21:59:41 by dmatesho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_ctwd(char const *s, char c)
{
	int num;

	num = 0;
	while (*s == c)
		s++;
	while (*s)
	{
		if (*s == c)
		{
			while (*s == c)
				s++;
			num++;
		}
		s++;
	}
	return (num);
}

static int		ft_wdl(char const *s, char c)
{
	int len;

	len = 0;
	while (*s != c && *s)
	{
		s++;
		len++;
	}
	return (len);
}

static char		**ft_strsplit(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		j;

	if (!s || !(ptr = (char **)malloc(sizeof(char **) * (ft_ctwd(s, c) + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
		{
			if (!(ptr[i] = (char *)malloc(sizeof(char *) * (ft_wdl(s, c) + 1))))
				return (NULL);
			j = 0;
			while (*s != c && *s)
				ptr[i][j++] = *s++;
			ptr[i][j] = 0;
			i++;
		}
	}
	ptr[i] = NULL;
	return (ptr);
}
