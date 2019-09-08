
#include "ft_ls.h"

void		ft_putlink(char *path)
{
	char	buf[256];
	ssize_t	len;

	len = readlink(path, buf, 255);
	buf[len] = '\0';
	ft_putstr(buf);
}