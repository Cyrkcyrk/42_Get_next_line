/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:33:32 by ckasyc            #+#    #+#             */
/*   Updated: 2021/01/06 01:53:20 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

typedef struct	s_gnl
{
	char	buf[BUFFER_SIZE];
	int		pos;
	int		len;
	int		line_nb;
	int		fd;
}				t_gnl;


int		get_to_line(int fd, int *count, char *buf, int line_nb)
{
	int		line_ct;

	line_ct = 0;
	while (line_ct < line_nb)
	{
		if ((count[1] = read(fd, buf, BUFFER_SIZE)) < 0)
			return (-1);
		count[0] = -1;
		while (++count[0] < count[1] && line_ct < line_nb)
			if (buf[count[0]] == '\n')
				line_ct++;
		if (count[1] == 0 && line_ct < line_nb)
			return (-1);
	}
	return (1);
	
}

int		get_next_line(int fd, char **line)
{
	static t_gnl	*info = 0;

	if (!info)
	{
		if (!(info = malloc(sizeof(t_gnl))))
			return (-1);
		info->pos = -2;
		info->line_nb = 0;
		info->fd = fd;
		info->len = -1;
	}
//	if (get_to_line(fd, count, buf, line_number) < 0)
//		return (-1);
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
				write(1, info->buf + info->pos, 1);
			}
		if ((info->len = read(fd, info->buf, BUFFER_SIZE)) < 0)
			return (-1);
		info->pos = -1;
	}
	return(0);
}

int main(int ac, char **av)
{
	char *ret;
	int fd;
	int t;
	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)
			return (-1);
		for (int i = 0; i< NBLINE; i++)
		{
			t = get_next_line(fd, &ret);
			printf(" - %d\n", t);
		}
	}
	return (1);
}
