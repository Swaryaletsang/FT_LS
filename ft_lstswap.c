#include "ft_ls.h"

static t_list		*lst_swap(t_list *lst1, t_list *lst2)
{
	lst1->next = lst2->next;
	lst2->next = lst1;
	return (lst2);
}

t_list	*lst_sort_ascii(t_list *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next && ft_strcmp(lst->content, lst->next->content) > 0)
		lst = lst_swap(lst, lst->next);
	lst->next = lst_sort_ascii(lst->next);
	if (lst->next && ft_strcmp(lst->content, lst->next->content) > 0)
	{
		lst = lst_swap(lst, lst->next);
		lst->next = lst_sort_ascii(lst->next);
	}
	return (lst);
}