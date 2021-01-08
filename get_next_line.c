/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:33:32 by ckasyc            #+#    #+#             */
/*   Updated: 2021/01/08 21:21:39 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

int		read_file(t_gnl *info, t_lst **list)
{
	char *c;

	while (info->len != 0)
	{
		if ((info->pos) >= -1)
			while (++(info->pos) < info->len)
			{
				if (info->buf[info->pos] == '\n' && info->pos < info->len)
					return (1);
				if ((info->buf[info->pos] == '\n' && info->pos == info->len &&
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
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static t_gnl	info = { .pos = -3 };
	t_lst			*list;
	int				ret;

	*line = NULL;
	if (!line || fd < 0)
		return (-1);
	list = NULL;
	if (info.pos == -3)
	{
		info.pos = -2;
		info.line_nb = -1;
		info.fd = fd;
		info.len = -1;
	}
	if (info.fd != fd)
		return (-1);
	info.line_nb++;
	if ((ret = read_file(&info, &list)) < 0)
		ret = -1;
	if (!(*line = lst_to_str(list)))
		ret = -1;
	ft_lstclear(&list, &free);
	return (ret);
}
