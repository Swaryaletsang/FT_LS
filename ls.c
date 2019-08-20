#include "ft_ls.h"

int    is_option(char c)
{
    char *str;
    int i;

    str = strdup("artlR");
    i = 0;
    while (str[i] != '\0')
    {
        if (c == str[i] && c == 'a')
            return (1);
        if (c == str[i] && c == 'r')
            return (2);
        if (c == str[i] && c == 't')
            return (3);
        if (c == str[i] && c == 'l')
            return (4);
        if (c == str[i] && c == 'R')
            return (5);
        i++;
    }
    return (0);
}

int    is_flag(char c)
{
    if(c == '-')
        return (1);
    return (0);
}

void    ft_lstdir(t_list *dir)
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

void    print_parse_f_d(t_list *lst)
{
    t_list *dir;
    t_list *files;
    
    dir = NULL;
    files = NULL;
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
        ft_putchar('\n');

        ft_lstdir(dir);
    }
}

int     main(int argc, char **argv)
{
    if (argc > 1)
    {
        char *flags;
        char *final_flags;
        int i;
        char err;
        t_list *sort_parsed;
        
        flags = ft_strdup("artRl");
        final_flags = ft_strnew(1);
        i = 1;
        while (i < argc)
        {
            if (is_flag(argv[i][0]) == 1)
                final_flags = ft_strcat(final_flags, argv[i]++);
            else
                break ;
            i++;
        }
        if (i < argc)
        {
          t_list *parsed_lst;

          parsed_lst =ft_lstnew(argv[i], ft_strlen(argv[i]));
          while (++i < argc)
          {
              ft_lstadd(&parsed_lst, ft_lstnew(argv[i], ft_strlen(argv[i])));
          }
          sort_parsed = ft_sort_list(parsed_lst, &compare);
          //ft_lstdel(&parsed_lst, &del);
          //ft_lstdel(&sort_parsed, &del);
        }
        print_parse_f_d(sort_parsed);
        /*if ((check_options(flags, final_flags)) == (int)(ft_strlen(final_flags)) - 1)
        {
            ft_putstr("hello im listing");
        }
        else
        {
             err = error_flag(flags, final_flags);
             ft_putstr("ft_ls: illegal option -- ");
             ft_putchar(err);
             ft_putchar('\n');
             ft_putendl("usage: ft_ls [-Ralrt] [file ...]");
         } */ 
    }
    return (0);
}