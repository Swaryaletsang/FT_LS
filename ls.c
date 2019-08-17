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

int     main(int argc, char **argv)
{
    if (argc > 1)
    {
        char *flags;
        char *final_flags;
        int i;
        char err;
        
        flags = ft_strdup("artRl");
        final_flags = ft_strnew(1);
        i = 1;
        while (i < argc)
        {
            if (is_flag(argv[i][0]) == 1)
            {
                final_flags = ft_strcat(final_flags, argv[i]++);
            }
            else
            {
                break ;
            }
            i++;
        }
        if ((check_options(flags, final_flags)) == (ft_strlen(final_flags)) - 1)
        {
            ft_putstr("hello im listing");
        }
        else
        {
            err = error_flag(flags, final_flags);
            ft_putstr("ls: illegal option -- ");
            ft_putchar(err);
            ft_putchar('\n');
            ft_putendl("usage: ls [-Ralrt] [file ...]");
        }
        
    }
    return (0);
}