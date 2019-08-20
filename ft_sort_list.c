#include "ft_ls.h"
//int		ft_timecmp(struct timespec *ts1, struct timespec *ts2);

t_list      *ft_sort_list(t_list *lst, int (*compare)(void *, void *))
{
    t_list *temp;
    void *swap;

    temp = lst;
    while (lst->next != NULL)
    {    
        if (((*compare)(lst->content, lst->next->content)) == 1)
        {
            swap = lst->next->content;
            lst->next->content = lst->content;
            lst->content = swap;
            lst = temp;
        }
        else
        {
            lst = lst->next;
        }
    }
    lst = temp;
    return (lst);
}
//int     comptime(void *s1, void *s2)
//{
    
//}
int     compare(void *s1, void *s2)
{
    int ret;
    char *str1;
    char *str2;

    str1 = (char *)s1;
    str2 = (char *)s2;

    ret = ft_strcmp(str1, str2);
    return (ret);
}
void	del(void *content, size_t size)
{
	(void)size;
	free(content);
}
void    display_list(t_list *elem)
{
    ft_putstr(elem->content);
    ft_putchar(' ');
}
void        ft_lst_rev(t_list *lst)
{
    t_list *tail;
    t_list *head;
    t_list *temp;

    tail = NULL;
    head = lst;
    while(head != NULL)
    {
        temp = head->next;
        head->next = tail;
        tail = head;
        head = temp;
    }
    lst = tail;
    ft_lstiter(lst, &display_list);
}
//int     main(void)
//{
  //  t_list *mylist;

    //mylist = ft_lstnew(".",2);
    //ft_lstadd(&mylist,ft_lstnew("..",3));
    //ft_lstadd(&mylist,ft_lstnew("hello",6));
    //ft_putendl("unsorted list");
    //ft_lstiter(mylist, &display_list);
    //ft_putchar('\n');
    //ft_putendl("POSIBLY SORTED LIST");
    //t_list *newlst = ft_sort_list(mylist,&ft_timecmp);
    //ft_lstiter(newlst, &display_list);
    //ft_putendl("REVERSED SORTED LIST");
    //ft_lst_rev(newlst);
    //return 0;
//}