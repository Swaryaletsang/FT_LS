/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 10:48:25 by atau              #+#    #+#             */
/*   Updated: 2019/06/03 14:19:35 by atau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(char *str)
{
	int	nb;
	int sign;
	int i;

	nb = 0;
	sign = 1;
	i = 0;
	if ((ft_strlen(str) >= 19) && (ft_strcmp("9223372036854775807", str) <= 0))
		return (-1);
	if ((ft_strlen(str) > 19) && (ft_strcmp("-9223372036854775808", str) <= 0))
		return (0);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}
