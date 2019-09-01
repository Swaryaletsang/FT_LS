/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 12:15:09 by atau              #+#    #+#             */
/*   Updated: 2019/09/01 13:26:28 by atau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		set_time(char *file_a, char *file_b, struct timespec *a,\
		struct timespec *b)
{
	struct stat		info;

	stat(file_a, &info);
	*a = info.st_mtimespec;
	stat(file_b, &info);
	*b = info.st_mtimespec;
}

t_list			*ft_sort_time(t_list *lst,\
		int (*time_compare)(struct timespec *, struct timespec *))
{
	t_list			*temp;
	void			*swap;
	struct timespec	time_a;
	struct timespec	time_b;

	temp = lst;
	while (lst->next != NULL)
	{
		set_time(lst->content, lst->next->content, &time_a, &time_b);
		if (((*time_compare)(&time_a, &time_b)) == -1)
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
