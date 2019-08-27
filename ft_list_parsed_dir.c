#include "ft_ls.h"

void    ft_list_parsed_dir(t_list *dir)
{
    t_list *list;
    t_list *sort_list;

    list = NULL;
    while (dir)
    {
        ft_putendl(dir->content);
        current_dir = opendir((char *)dir->content);
        while((r = readdir(current_dir)))
        {
		    if(r->d_name[0] != '.')
		    {
			    ft_lstadd(&list, ft_lstnew(r->d_name, ft_strlen(r->d_name) + 1));
            }
	    }
        sort_list = ft_sort_list(list, &compare);
        ft_lstiter(sort_list, &display_list);
        ft_lstdel(&list, &del);
        ft_putchar('\n');
        dir = dir->next;
    }
        closedir(current_dir);
}