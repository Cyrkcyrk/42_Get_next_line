/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:33:32 by ckasyc            #+#    #+#             */
/*   Updated: 2021/01/09 20:54:21 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line_bonus.h"

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

void	fill_struct(t_gnl *info)
{
	int i;

	i = -1;
	while (++i < MAX_FD)
	{
		info[i].pos = -2;
		info[i].len = -1;
		info[i].fd = -1;
	}
}

int		get_next_line(int fd, char **line)
{
	static t_gnl	info[MAX_FD] = {{.buf = "", .pos = -3, .len = -1,
									.fd = -1}};
	t_lst			*list;
	int				ret;

	*line = NULL;
	if (!line || fd < 0 || fd >= MAX_FD)
		return (-1);
	list = NULL;
	if (info[0].pos == -3)
		fill_struct(info);
	if (info[fd].fd == -1)
		info[fd].fd = fd;
	if ((ret = read_file(&info[fd], &list)) < 0)
		ret = -1;
	if (ret != -1 && !(*line = lst_to_str(list)))
		ret = -1;
	ft_lstclear(&list, &free);
	return (ret);
}
