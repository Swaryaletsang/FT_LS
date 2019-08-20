#include "ft_ls.h"

int		check_options(char *s,  char *s2)
{
	int i;
	int count;
    int x;

    x = 0;
	count = 0;
    while (s2[x] != '\0')
    {
        i = 0;
	    while (s[i] != '\0')
	    {
		    if (s[i] == s2[x])
			    count++;
		    i++;
	    }
        x++;
    }
	return(count);
}

char	error_flag(char *s, char *s1)
{
	int i;
	int count;
    int x;
	int p;

    x = 1;
	count = 0;
	p = 0;
    while (s1[x] != '\0')
    {
        i = 0;
	    while (s[i] != '\0')
	    {
		    if (s[i] == s1[x])
			    count++;
		    i++;
	    }
		
		if (p == count)
			return(s1[x]);
		p = count;
        x++;
    }
	return (' ');
}