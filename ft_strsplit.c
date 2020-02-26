/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatesho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:07:56 by dmatesho          #+#    #+#             */
/*   Updated: 2020/02/25 19:32:50 by dmatesho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//**hhh**gg*ds*****fyyd**


int	ft_countwords(char const *s, char c)
{
	int num;

	while (*s == c)
		s++;
	while (*s)
	{
		if (*s == c)
		{
			while (*s != c)
				s++;
			num++;
		}
		s++;
	}
	return (num);
}

/*
char	**ft_strsplit(char const *s, char c)
{
	if (!s
	*/
#include <stdio.h>

int	main(void)
{
	char str[] = "**hhh**gg*ds*****fyyd**";

	int nn = ft_countwords(str, '*');
	printf("%d", nn);
}
