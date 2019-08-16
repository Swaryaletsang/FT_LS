
#include "ft_ls.h"

int		ft_timecmp(struct timespec *ts1, struct timespec *ts2)
{
	if ((double)(ts1->tv_sec - ts2->tv_sec) < 0)
		return (-1);
	else if ((double)(ts1->tv_sec - ts2->tv_sec) == 0)
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
