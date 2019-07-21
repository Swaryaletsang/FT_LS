/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:48:44 by atau              #+#    #+#             */
/*   Updated: 2019/06/14 16:58:42 by atau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (destsize < ft_strlen(dest))
		return (destsize + ft_strlen(src));
	while (dest[i] && i < destsize)
		i++;
	j = i;
	while (src[i - j] && i < destsize - 1)
	{
		dest[i] = src[i - j];
		i++;
	}
	if (j < destsize)
		dest[i] = '\0';
	return (j + ft_strlen(src));
}
