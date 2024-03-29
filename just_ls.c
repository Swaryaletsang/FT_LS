/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:13:58 by atau              #+#    #+#             */
/*   Updated: 2019/09/13 14:10:14 by atau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		just_ls(void)
{
	t_list		*ls_list;
	t_list		*sort_ls;
	DIR			*current_dir;

	ls_list = NULL;
	current_dir = opendir(".");
	while ((r = readdir(current_dir)))
	{
		if (r->d_name[0] != '.')
			ft_lstadd(&ls_list, ft_lstnew(r->d_name, ft_strlen(r->d_name) + 1));
	}
	sort_ls = ft_sort_list(ls_list, &compare);
	ft_lstiter(sort_ls, &display_list);
	ft_putchar('\n');
	closedir(current_dir);
	ft_lstdel(&ls_list, &del);
}
