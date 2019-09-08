/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:47:23 by atau              #+#    #+#             */
/*   Updated: 2019/09/08 15:48:04 by atau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*full_path(char *content, char *path)
{
	char *path_content;
	char *temp;

	if (path != NULL)
	{
		temp = ft_strjoin(path, "/");
		path_content = ft_strjoin(temp, content);
		free(temp);
	}
	else
		path_content = content;
	return (path_content);
}
