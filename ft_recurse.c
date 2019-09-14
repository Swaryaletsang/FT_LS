/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recurse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:10:37 by atau              #+#    #+#             */
/*   Updated: 2019/09/13 14:12:27 by atau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void     recurse_dir(char *path, char *flags)
{
    t_list *mylist;
    char    *newdir;
    DIR     *dp;

    mylist = creat_lst_dir(path, flags);
    ft_putstr(path);
    ft_putendl(":");
    ft_finally_print(mylist, flags, path);
    //ft_lstdel(&mylist, &del);

    dp = opendir(path);
    newdir = ft_strnew(0);
    while ((r = readdir(dp)))
    {
        if(ft_strncmp(r->d_name, ".", 1))
        {
            if ((is_option('R', flags) != 0) && r->d_type == 4)
            {
                newdir = full_path(r->d_name, path);
                recurse_dir(newdir, flags);
                ft_strdel(&newdir);
            }
        }
        ft_strdel(&newdir);
    }
    //ft_strdel(&newdir);
    closedir(dp);
}

void        recurse(t_list *list, char *options, char *parsed_path)
{
    char    *path;

    if (parsed_path == NULL)
        parsed_path = ft_strdup(".");
    while (list)
    {
        path = full_path(list->content, parsed_path);
        if (lstat(path, &stats) == 0)
             if (S_ISDIR(stats.st_mode))
                recurse_dir(path, options);
        list = list->next;
        ft_strdel(&path);
    }
    ft_strdel(&parsed_path);
}
