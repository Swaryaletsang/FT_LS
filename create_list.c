
#include "ft_ls.h"

t_list		*creat_lst_dir(char *directory, char *option)
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