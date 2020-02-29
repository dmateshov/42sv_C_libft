/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatesho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 22:17:42 by dmatesho          #+#    #+#             */
/*   Updated: 2020/02/25 22:54:52 by dmatesho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *nlist;

	if (!(nlist = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		nlist->content = NULL;
		nlist->content_size = 0;
	}
	else
	{
		if (!(nlist->content = (void *)malloc(content_size)))
			return (NULL);
		ft_memcpy(nlist->content, content, content_size);
		nlist->content_size = content_size;
	}
	nlist->next = NULL;
	return (nlist);
}
