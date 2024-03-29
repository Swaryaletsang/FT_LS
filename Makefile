# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atau <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 13:10:24 by atau              #+#    #+#              #
#    Updated: 2019/09/10 14:22:14 by atau             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
FLAG = -Wall -Werror -Wextra
CC = gcc
OPTION = -o
SRC = check_options.c compare.c del.c display_list.c ft_list_parsed_dir.c ft_ls.c ft_lst_rev.c \
	  ft_sort_time.c ft_sort.c ft_timecmp.c is_option.c long_ls.c print_ls.c print_parsed_f_d.c \
	  create_list.c ft_recurse.c full_path.c ext_attr.c ft_put_link.c just_ls.c ft_lstswap.c
LIB = -L libft/ -lft -I
all: $(NAME)

$(NAME):
	@make -C libft/
	@$(CC) $(OPTION) $(NAME) $(SRC) $(LIB) $(FLAG)

clean:
	@make fclean -C libft/

fclean: clean
	@rm -f $(NAME)

re: fclean all
