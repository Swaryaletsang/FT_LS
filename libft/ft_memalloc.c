/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 09:06:47 by atau              #+#    #+#             */
/*   Updated: 2019/05/29 10:14:40 by atau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	char	*memory;
	size_t	i;

	i = 0;
	memory = (char *)malloc(size);
	if (!(memory))
		return (NULL);
	while (i < size)
	{
		memory[i] = 0;
		i++;
	}
	return (memory);
}
