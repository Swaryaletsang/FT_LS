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

static void     recurse_dir(char *path, char *flags, char *dir_path)
{
    t_list *lst;
    char    *final_path;
    char *inner_path;
    // t_list *head;

    final_path = full_path(path, dir_path);
    lst = creat_lst_dir(final_path, flags);
    ft_finally_print(lst, flags, final_path);
    // head = lst;
    inner_path = full_path((char *)lst->content, final_path);
    while (lst)
    {
        
        if (lstat(inner_path, &stats) == 0)
             if (S_ISDIR(stats.st_mode))
             {
                ft_putendl(inner_path);
                recurse_dir(inner_path, flags, dir_path);
             }
        lst = lst->next;
        // free(inner_path);
    }
    // lst = head;
    // if (lst) 
    //     ft_lstdel(&lst, &del);
}

void        recurse(t_list *list, char *options, char *path)
{
    if (path == NULL)
        path = ft_strdup(".");
    while (list)
    {
        if (lstat(list->content, &stats) == 0)
             if (S_ISDIR(stats.st_mode))
                recurse_dir(list->content, options, path);
        list = list->next;
    }
    return ;
}
