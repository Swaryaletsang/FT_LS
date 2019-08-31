/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 15:20:14 by atau              #+#    #+#             */
/*   Updated: 2019/06/14 16:54:50 by atau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)hay);
	while (hay[i] != '\0' && i < len)
	{
		j = 0;
		while (hay[i + j] == needle[j] && ((i + j) < len))
		{
			ptr = ((char *)&hay[i]);
			if (needle[j + 1] == '\0')
				return (ptr);
			j++;
		}
		i++;
	}
	return (NULL);
}
