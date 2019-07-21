/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:00:43 by atau              #+#    #+#             */
/*   Updated: 2019/05/29 17:21:17 by atau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	str = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	i = 0;
	if (str != NULL)
	{
		while (s1[i] != '\0')
		{
			str[i] = (char)s1[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
