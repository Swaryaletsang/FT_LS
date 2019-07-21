/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:27:40 by atau              #+#    #+#             */
/*   Updated: 2019/06/14 17:31:15 by atau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		st_wordcount(char *str, char c)
{
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static int		ft_skipi(char const *s, int i, char c)
{
	while (s[i] == c)
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		numofwrd;
	int			i;
	char		**arr;
	int			j;
	size_t		wrd;

	if (s == NULL)
		return (NULL);
	numofwrd = st_wordcount((char *)s, c);
	if (!(arr = (char **)malloc(sizeof(char *) * numofwrd + 1)))
		return (NULL);
	i = 0;
	wrd = 0;
	while (wrd < numofwrd)
	{
		i = ft_skipi(s, i, c);
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (j < i)
			arr[wrd++] = ft_strsub(s, j, (i - j));
		i++;
	}
	arr[wrd] = NULL;
	return (arr);
}
