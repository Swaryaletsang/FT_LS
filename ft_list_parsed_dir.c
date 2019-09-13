/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_parsed_dir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 15:30:54 by atau              #+#    #+#             */
/*   Updated: 2019/09/08 15:58:59 by atau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_list_size(t_list *begin_list)
{
	t_list	*list;
	int		index;

	index = 0;
	list = begin_list;
	while (list)
	{
		index++;
		list = list->next;
	}
	return (index);
}

void		ft_list_parsed_dir(t_list *dir, char *flags)
{
	t_list	*list;
	int		size;

	size = ft_list_size(dir);
	list = NULL;
	while (dir)
	{
		if (size > 1)
		{
			ft_putstr((char *)dir->content);
			ft_putendl(":");
		}
		list = creat_lst_dir((char *)dir->content, flags);
		ft_finally_print(list, flags, (char *)dir->content);
		ft_putchar('\n');
		if (is_option('R', flags) != 0)
			recurse(list, flags, (char *)dir->content);
			
		if (dir->next != NULL)
			ft_putchar('\n');
		dir = dir->next;
	}
}
