/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 13:50:56 by atau              #+#    #+#             */
/*   Updated: 2019/06/07 18:13:39 by atau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1)
{
	char	*str;
	int		i;
	int		len;
	int		j;
	int		finallen;

	if (!s1)
		return (NULL);
	i = 0;
	while (ft_isspace(s1[i]))
		i++;
	len = ft_strlen(s1);
	while ((ft_isspace(s1[len]) || s1[len] == '\0') && len > 0)
		len--;
	finallen = len - i;
	if (finallen < 0)
		finallen = -1;
	if (!(str = (char *)malloc(sizeof(char) * (finallen + 2))))
		return (NULL);
	j = 0;
	while (s1[i] != '\0' && i <= len)
		str[j++] = s1[i++];
	str[j] = '\0';
	return (str);
}
