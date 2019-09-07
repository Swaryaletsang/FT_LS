#include "ft_ls.h"

// char        *get_directory(t_list *list)
// {
//     struct stat info;
//     char    *is_dir;
    
//     while (list)
//     {
//         if (lstat(list->content, &info) == 0)
//         {
//             if (S_ISDIR(stats.st_mode))
//             {
//                 is_dir = ft_strdup(list->content);
//             }
//         }
//     }
// }

void        recurse(t_list *list, char *options)
{
    t_list *lst;

    //ft_lstiter(list, &display_list);
    lst = NULL;
    while (list)
    {
        if (lstat(list->content, &stats) == 0)
        {
             if (S_ISDIR(stats.st_mode))//|| S_ISLNK(stats.st_mode))
            {
                lst = creat_lst_dir(list->content, options); 
                ft_finally_print(lst, options, "get path tomorrow");
                ft_putchar('\n'); 
            }
        }
        //sleep(2);
        list = list->next;
    }
    return ;
}