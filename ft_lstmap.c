/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatesho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 23:12:48 by dmatesho          #+#    #+#             */
/*   Updated: 2020/02/25 23:31:13 by dmatesho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *cur;
	t_list *ncur;

	cur = lst;
	new = f(cur);
	ncur = new;
	while (cur)
	{
		cur = cur->next;
		ncur->next = f(cur);
		ncur = ncur->next;
	}
	return (new);
}
