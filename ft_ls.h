#ifndef FT_LS_H
# define FT_LS_H
#include <sys/types.h>
#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>
#include <sys/stat.h>
#include "libft/libft.h"
struct stat stats;
struct passwd *user;
struct group *grp;
DIR *current_dir;
struct dirent *r;

void        ft_ls();
int		ft_timecmp(struct timespec *ts1, struct timespec *ts2);
char	error_flag(char *s, char *s1);
int		check_options(char *s,  char *s2);
int     compare(void *s1, void *s2);
void    print_parse_f_d(t_list *lst);
t_list      *ft_sort_list(t_list *lst, int (*compare)(void *, void *));
void	del(void *content, size_t size);
void    display_list(t_list *elem);
#endif