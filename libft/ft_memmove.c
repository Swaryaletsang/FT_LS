/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 09:25:11 by atau              #+#    #+#             */
/*   Updated: 2019/06/03 14:24:20 by atau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;

	d = (char *)dest;
	s = (char *)src;
	if (src == dest)
		return (dest);
	i = 0;
	if (dest > src)
	{
		i = len;
		while (i-- > 0)
			d[i] = s[i];
	}
	else
	{
		while (len > i)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
