/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_parsed_dir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 15:30:54 by atau              #+#    #+#             */
/*   Updated: 2019/09/02 14:52:49 by atau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_list		*creat_lst_dir(char *directory, char *option)
{
	t_list	*ls_list;
	t_list	*sort_ls;
	DIR		*current_dir;
	size_t	len;

	ls_list = NULL;
	len = 0;
	current_dir = opendir(directory);
	if (is_option('a', option) == 0)
	{
		while ((r = readdir(current_dir)))
		{
			len = ft_strlen(r->d_name) + 1;
			if (r->d_name[0] != '.')
				ft_lstadd(&ls_list, ft_lstnew(r->d_name, len));
		}
	}
	else
	{
		while ((r = readdir(current_dir)))
			ft_lstadd(&ls_list, ft_lstnew(r->d_name, ft_strlen(r->d_name) + 1));
	}
	sort_ls = ft_sort_list(ls_list, &compare);
	return (sort_ls);
	closedir(current_dir);
}

void	ft_list_parsed_dir(t_list *dir, char *flags)
{
	t_list *list;
	//t_list *sort_list;
	//DIR *current_dir;

	list = NULL;
	while (dir)
	{
		ft_putstr(dir->content);
		ft_putendl(":");
		// current_dir = opendir((char *)dir->content);
		// while ((r = readdir(current_dir)))
		// {
		// 	if (r->d_name[0] != '.')
		// 	{
		// 		ft_lstadd(&list, ft_lstnew(r->d_name,\
		// 					ft_strlen(r->d_name) + 1));
		//  	}	
		// }
		// sort_list = ft_sort_list(list, &compare);
		list = creat_lst_dir(dir->content, flags);
		ft_finally_print(list, flags);
		//ft_lstdel(&list, &del);
		ft_putchar('\n');
		dir = dir->next;
		//closedir(current_dir);
	}
}