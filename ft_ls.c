#include "ft_ls.h"
#include "libft/libft.h"

void ft_ls()
{
    DIR *current_dir;
    struct dirent *r;
    

    current_dir = opendir(".");
    while((r = readdir(current_dir)))
    {
		if(r->d_name[0] != '.')
		{
			ft_putstr(r->d_name);
			ft_putchar(' ');
			ft_putchar(' ');
	}
    closedir(current_dir);
}
