/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 12:50:12 by atau              #+#    #+#             */
/*   Updated: 2019/06/14 17:15:11 by atau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		st_countdigit(int n)
{
	int count;

	count = 1;
	if (n < 0)
	{
		n = n * (-1);
		count++;
	}
	while ((n = n / 10))
		count++;
	return (count);
}

char			*ft_itoa(int n)
{
	char			*str;
	int				dig;

	if (n == -2147483648)
	{
		str = (char *)malloc(sizeof(char) * 12);
		return (ft_strcpy(str, "-2147483648"));
	}
	dig = st_countdigit(n);
	if (!(str = (char *)malloc(sizeof(char) * dig + 1)))
		return (NULL);
	str[0] = '0';
	str[dig--] = '\0';
	while (n)
	{
		if (n < 0)
		{
			n = n * (-1);
			str[0] = '-';
		}
		str[dig--] = ((n % 10) + '0');
		n = n / 10;
	}
	return (str);
}
