/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 18:15:38 by atau              #+#    #+#             */
/*   Updated: 2019/09/08 15:55:33 by atau             ###   ########.fr       */
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
# include <sys/xattr.h>
# include "libft/libft.h"

struct stat		stats;
struct passwd	*user;
struct group	*grp;
struct dirent	*r;
struct timespec	time_a;
struct timespec	time_b;

void			recurse(t_list *list, char *options);
void			ft_putlink(char *path);
char			*full_path(char *content, char *path);
void			ext_attr(char *path);
t_list			*creat_lst_dir(char *directory, char *option);
void			long_ls(char *path, char *dir_path);
int				is_option(char c, char *str);
int				ft_timecmp(struct timespec *ts1, struct timespec *ts2);
int				compare(void *s1, void *s2);
t_list			*ft_sort_time(t_list *lst,\
		int (*time_compare)(struct timespec *, struct timespec *), char *path);
t_list			*ft_lst_rev(t_list *lst);
void			print_parsed_f_d(t_list *lst, char *flags);
t_list			*ft_sort_list(t_list *lst, int (*compare)(void *, void *));
void			del(void *content, size_t size);
void			display_list(t_list *elem);
void			ft_list_parsed_dir(t_list *dir, char *flags);
void			ls_with_flags(char *s1, char *s2);
t_list			*ft_sort_list(t_list *lst, int (*compare)(void *, void *));
void			ft_finally_print(t_list *list, char *final_flags,\
		char *dir_path);

#endif
