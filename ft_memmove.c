/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatesho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:21:44 by dmatesho          #+#    #+#             */
/*   Updated: 2020/02/27 13:30:26 by dmatesho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*ptr_dst;
	const char	*ptr_src;
	size_t		i;

	if (!dst || !src || !len)
		return (dst);
	ptr_dst = (char *)dst;
	ptr_src = (const char *)src;
	if (ptr_src < ptr_dst)
	{
		i = 1;
		while (i <= len)
		{
			ptr_dst[len - i] = ptr_src[len - i];
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			ptr_dst[i] = ptr_src[i];
			i++;
		}
	}
	return (dst);
}
