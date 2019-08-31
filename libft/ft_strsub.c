/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 08:45:58 by atau              #+#    #+#             */
/*   Updated: 2019/06/03 14:21:45 by atau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(substr = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (len > i)
	{
		substr[i++] = s[start++];
	}
	substr[i] = '\0';
	return (substr);
}
