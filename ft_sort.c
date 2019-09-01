/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 12:27:04 by atau              #+#    #+#             */
/*   Updated: 2019/09/01 13:21:03 by atau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list			*ft_sort_list(t_list *lst, int (*compare)(void *, void *))
{
	t_list	*temp;
	void	*swap;

	temp = lst;
	while (lst->next != NULL)
	{
		if (((*compare)(lst->content, lst->next->content)) == 1)
		{
			swap = lst->next->content;
			lst->next->content = lst->content;
			lst->content = swap;
			lst = temp;
		}
		else
			lst = lst->next;
	}
	lst = temp;
	return (lst);
}
