/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 11:29:25 by atau              #+#    #+#             */
/*   Updated: 2019/09/15 15:22:20 by atau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		format(char *s, char c)
{
	ft_putstr(s);
	ft_putchar(c);
}

static void		permisions2(void)
{
	if (stats.st_mode & S_IRGRP)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (stats.st_mode & S_IWGRP)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (stats.st_mode & S_IXGRP)
		ft_putchar('x');
	else
		ft_putchar('-');
	if (stats.st_mode & S_IROTH)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (stats.st_mode & S_IWOTH)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (stats.st_mode & S_IXOTH)
		ft_putchar('x');
	else
		ft_putchar('-');
}

static void		permisions1(char *path)
{
	if (S_ISDIR(stats.st_mode))
		ft_putchar('d');
	else if (S_ISLNK(stats.st_mode))
		ft_putchar('l');
	else
		ft_putchar('-');
	if (stats.st_mode & S_IRUSR)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (stats.st_mode & S_IWUSR)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (stats.st_mode & S_ISUID)
		ft_putchar('S');
	else if (stats.st_mode & S_IXUSR)
		ft_putchar('x');
	else
		ft_putchar('-');
	permisions2();
	ext_attr(path);
	ft_putchar(' ');
}

static void		long_ls_contents(void)
{
	char	**r;
	char	*s;
	char	*s1;
	int		i;

	ft_putnbr(stats.st_nlink);
	ft_putchar(' ');
	user = getpwuid(stats.st_uid);
	format(user->pw_name, ' ');
	grp = getgrgid(stats.st_gid);
	format(grp->gr_name, ' ');
	ft_putnbr(stats.st_size);
	ft_putchar(' ');
	s = ft_strdup(ctime(&stats.st_mtime));
	s1 = ft_strsub(s, 4, 12);
	r = ft_strsplit(s1, ' ');
	format(r[1], ' ');
	format(r[0], ' ');
	format(r[2], ' ');
	i = 0;
	while (r[i] != NULL)
		ft_strdel(&(r[i++]));
	free(r);
	ft_strdel(&s);
	ft_strdel(&s1);
}

void			long_ls(char *path, char *dir_path)
{
	char *path_content;

	path_content = full_path(path, dir_path);
	if ((lstat(path_content, &stats)) == 0)
	{
		permisions1(path_content);
		long_ls_contents();
		ft_putstr(path);
		if (S_ISLNK(stats.st_mode))
		{
			ft_putstr(" -> ");
			ft_putlink(path_content);
		}
		ft_putchar('\n');
	}
	ft_strdel(&path_content);
}
