/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 11:32:53 by atau              #+#    #+#             */
/*   Updated: 2019/06/14 14:39:36 by atau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *temp;

	if (!lst || !f)
		return (NULL);
	new = f(lst);
	temp = new;
	while ((lst = lst->next))
	{
		temp->next = f(lst);
		temp = temp->next;
	}
	return (new);
}
