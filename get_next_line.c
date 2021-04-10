/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:33:32 by ckasyc            #+#    #+#             */
/*   Updated: 2021/04/10 17:11:18 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

//#include <stdio.h>
//#include <stdlib.h>
//#include <fcntl.h>


char*	 concat_str(char** line, char *second, unsigned int size)
{
	unsigned int	total_size;
	unsigned int	first_size;
	char*			ret;
	
	first_size = ft_strlen(*line);
	total_size = first_size + size + 1;
	if (!(ret = (char*) malloc(total_size * sizeof(char))))
		return (NULL);
	ret[0] = '\0';
	ft_strlcat(ret, *line, first_size);
	ft_strlcat(ret, second, total_size);
	free (*line);
	*line = ret;
	return (ret);
}


int		read_file(t_gnl *info, char** line)
{
	int		start;

	while (info->len != 0)
	{
		if (info->pos >= -1)
		{
			start = info->pos + 1;
			while (++(info->pos) < info->len)
			{
				if (info->buf[info->pos] == '\n')
				{
					if (!concat_str(line, &(info->buf[start]), (info->pos - start)))
						return (-1);
					return(1);
				}
			}
		}
		if ((info->len = read(info->fd, info->buf, BUFFER_SIZE)) < 0)
			return (-1);
		info->pos = -1;
	}
	if(!concat_str(line, &(info->buf[start]), (info->pos - start)))
		return (-1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static t_gnl	info = { .pos = -3 };
	
	if (!line || fd < 0)
		return (-1);
	if (info.pos == -3)
	{
		info.pos = -1;
		info.line_nb = -1;
		info.fd = fd;
		info.len = -1;
	}
	if (info.fd != fd)
		return (-1);
	if (!(*line = malloc(sizeof(char))))
		return (-1);
	*line[0] = '\0';
	info.line_nb++;
	return (read_file(&info, line));
}
