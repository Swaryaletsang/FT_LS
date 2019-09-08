/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_attr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:59:22 by atau              #+#    #+#             */
/*   Updated: 2019/09/08 16:00:39 by atau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ext_attr(char *path)
{
	char	chr;
	ssize_t	xattr;

	xattr = 0;
	xattr = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	if (xattr < 0)
		xattr = 0;
	if (xattr > 0)
		chr = '@';
	else
		chr = ' ';
	ft_putchar(chr);
	ft_putchar(' ');
}
