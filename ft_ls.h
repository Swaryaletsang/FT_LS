/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 18:15:38 by atau              #+#    #+#             */
/*   Updated: 2019/08/31 18:22:55 by atau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <sys/types.h>
# include <dirent.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>
# include <sys/stat.h>
# include "libft/libft.h"

struct stat		stats;
struct passwd	*user;
struct group	*grp;
DIR				*current_dir;
struct dirent	*r;

void			ft_ls();
int				ft_timecmp(struct timespec *ts1, struct timespec *ts2);
t_list			*ft_sort_by_time(t_list *lst,\
				int (*time_compare)(struct timespec *, struct timespec *));
char			error_flag(char *s, char *s1);
int				check_options(char *s, char *s2);
int				compare(void *s1, void *s2);
void			print_parse_f_d(t_list *lst);
t_list			*ft_sort_list(t_list *lst, int (*compare)(void *, void *));
void			del(void *content, size_t size);
void			display_list(t_list *elem);
void			ft_list_parsed_dir(t_list *dir);
void			ls_with_flags(char *s1, char *s2);

#endif
