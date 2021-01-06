/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:33:32 by ckasyc            #+#    #+#             */
/*   Updated: 2021/01/07 00:06:05 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"
#include <stdio.h>

int		read_file(t_gnl *info, t_lst **list)
{
	char *c;

	while(info->len != 0)
	{
		if ((info->pos) >= -1)
			while(++(info->pos) < info->len)
			{
				if (info->buf[info->pos] == '\n' && info->pos < info->len )
					return (1);
				if((info->buf[info->pos] == '\n' && info->pos == info->len &&
					info->len < BUFFER_SIZE) || info->len == 0)
					return (0);
				if (!(c = malloc(sizeof(char))))
					return (-1);
				*c = info->buf[info->pos];
				if (lst_pushback(list, c) < 0)
					return (-1);
			}
		if ((info->len = read(info->fd, info->buf, BUFFER_SIZE)) < 0)
			return (-1);
		info->pos = -1;
	}
	return(0);
}

int		get_next_line(int fd, char **line)
{
	static t_gnl	*info = 0;
	t_lst			*list;
	int				ret;
	
	list = NULL;
	if (!info)
	{
		if (!(info = malloc(sizeof(t_gnl))))
			return (-1);
		info->pos = -2;
		info->line_nb = 0;
		info->fd = fd;
		info->len = -1;
	}
	if((ret = read_file(info, &list)) < 0 || !(*line = lst_to_str(list)))
	{
		return (-1);
	}
	//if (!(*line = lst_to_str(list)))
	//	return (-1);
	ft_lstclear(&list, &free);
	//printf("%s", *line);
	return (ret);
}
