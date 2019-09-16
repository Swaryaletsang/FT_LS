/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timecompare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 13:24:58 by atau              #+#    #+#             */
/*   Updated: 2019/09/01 13:25:38 by atau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_timecmp(struct timespec *ts1, struct timespec *ts2)
{
	if ((long)(ts1->tv_sec - ts2->tv_sec) < 0)
		return (-1);
	else if ((long)(ts1->tv_sec - ts2->tv_sec) == 0)
	{
		if ((ts1->tv_nsec - ts2->tv_nsec) < 0)
			return (-1);
		else if ((ts1->tv_nsec - ts2->tv_nsec) > 0)
			return (1);
		else
			return (0);
	}
	else
		return (1);
}
