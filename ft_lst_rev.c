/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 12:37:09 by atau              #+#    #+#             */
/*   Updated: 2019/09/01 12:44:00 by atau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list		*ft_lst_rev(t_list *lst)
{
	t_list *tail;
	t_list *head;
	t_list *temp;

	tail = NULL;
	head = lst;
	while (head != NULL)
	{
		temp = head->next;
		head->next = tail;
		tail = head;
		head = temp;
	}
	lst = tail;
	return (lst);
}
