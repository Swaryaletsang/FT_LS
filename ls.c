#include "ft_ls.h"

int    is_option(char c)
{
    char *str;
    int i;

    str = strdup("-artlR");
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

int     main(int argc, char **argv)
{
    if (argc == 2 && ft_strcmp("--", argv[1]) == 0)
    {
        ft_ls();
        return (0);
    }
    else if (argc > 1) 
    {
        char *flags;
        char *final_flags;
        int i;
        t_list *sort_parsed;
        
        flags = ft_strdup("artRl");
        final_flags = ft_strnew(1);
        i = 1;
        sort_parsed = NULL;
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

          parsed_lst =ft_lstnew(argv[i], ft_strlen(argv[i]) + 1);
          while (++i < argc)
          {
              ft_lstadd(&parsed_lst, ft_lstnew(argv[i], ft_strlen(argv[i]) + 1));
          }
          sort_parsed = ft_sort_list(parsed_lst, &compare);
        }
        print_parse_f_d(sort_parsed);

        if (ft_strlen(final_flags) > 0)
            ls_with_flags(flags,final_flags);    
    }
    else
        ft_ls();
    return (0);
}