#include "ft_ls.h"

void    print_parse_f_d(t_list *lst)
{
    t_list *dir;
    t_list *files;
    t_list *temp;
    
    dir = NULL;
    files = NULL;
    temp = lst;
    while(lst)
    {
        if ((stat(lst->content, &stats)) == 0)
        {
            if (S_ISDIR(stats.st_mode))
                ft_lstadd(&dir, ft_lstnew(lst->content, ft_strlen(lst->content) + 1));
	        if (S_ISREG(stats.st_mode))
                ft_lstadd(&files, ft_lstnew(lst->content, ft_strlen(lst->content) + 1));
        }
        else
        {
                ft_putstr("ft_ls: ");
                ft_putstr(lst->content);
                ft_putendl(": No such file or directory");
        }
        lst = lst->next;
    }
    ft_lstiter(files, &display_list);
    if (dir != NULL)
    {
        t_list *temp;

        temp = ft_sort_list(dir, &compare);
        ft_list_parsed_dir(temp);

    }
}