/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 16:25:55 by atau              #+#    #+#             */
/*   Updated: 2019/06/07 17:14:06 by atau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *hay, const char *needle)
{
	int		i;
	int		j;
	char	*ptr;

	if (needle[0] == '\0')
		return ((char *)hay);
	i = 0;
	while (hay[i] != '\0')
	{
		j = 0;
		while (hay[i + j] == needle[j])
		{
			ptr = (char *)&hay[i];
			if (needle[j + 1] == '\0')
				return (ptr);
			j++;
		}
		i++;
	}
	return (NULL);
}
