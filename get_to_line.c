/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_to_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 23:52:29 by ckasyc            #+#    #+#             */
/*   Updated: 2021/01/06 23:52:47 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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
