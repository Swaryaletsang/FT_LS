#include "ft_ls.h"

char        *get_directory(t_list *list)
{
    struct stat info;
    char    *is_dir;
    
    while (list)
    {
        if (lstat(list->content, &info) == 0)
        {
            if (S_ISDIR(stats.st_mode))
            {
                is_dir = ft_strdup(list->content);
            }
        }
    }
}