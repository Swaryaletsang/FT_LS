#include "ft_ls.h"
#include "libft/libft.h"

void ft_ls()
{
    t_list *ls_list;
    t_list *sort_ls;

    ls_list = NULL;
    current_dir = opendir(".");
    while((r = readdir(current_dir)))
    {
		if(r->d_name[0] != '.')
		{
            ft_lstadd(&ls_list, ft_lstnew(r->d_name, ft_strlen(r->d_name) + 1));
		}
	}
    sort_ls = ft_sort_list(ls_list, &compare);
    ft_lstiter(sort_ls, &display_list);
    closedir(current_dir);
}
