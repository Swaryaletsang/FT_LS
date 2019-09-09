#include "ft_ls.h"

void        recurse(t_list *list, char *options, char *path)
{
    t_list *lst;
    char *final_path;
    char *directory;

    if (path == NULL)
        path = ft_strdup(".");
    lst = NULL;
    while (list)
    {
        final_path = full_path(list->content, path);
        if (lstat(final_path, &stats) == 0)
        {
             if (S_ISDIR(stats.st_mode))
            {
                ft_putendl(list->content);
                sleep(1);
                lst = creat_lst_dir(final_path, options); 
                ft_finally_print(lst, options, final_path);
                ft_lstdel(&lst, &del);
            }
        }
        ft_strdel(&final_path);
        list = list->next;
    }
    return ;
}
