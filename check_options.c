/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 15:49:42 by atau              #+#    #+#             */
/*   Updated: 2019/09/08 16:02:43 by atau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		check_options(char *s, char *s2)
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
	return (count);
}

static char		error_flag(char *s, char *s1)
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
			return (s1[x]);
		p = count;
		x++;
	}
	return (' ');
}

void			ls_with_flags(char *s1, char *s2)
{
	char	err;

	if ((check_options(s1, s2)) == (int)(ft_strlen(s2)) - 1)
		ft_finally_print(NULL, s2, NULL);
	else
	{
		err = error_flag(s1, s2);
		ft_putstr("ft_ls: illegal option -- ");
		ft_putchar(err);
		ft_putchar('\n');
		ft_putendl("usage: ft_ls [-Ralrt] [file ...]");
		return ;
	}
}
