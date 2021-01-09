/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 00:04:03 by ckasyc            #+#    #+#             */
/*   Updated: 2021/01/09 19:54:51 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

void	doprint(int out, int fd, char **str, int line)
{
	printf("%2i - (FD %d) [OUT %i] |%s|\n", line, fd, out, *str);
	if (*str)
		free(*str);
	*str = NULL;
}

int main(int ac, char **av)
{
	char *ret;
	int fd[ac];
	int t;
	int i;
	int j;
	int ct;
	
	ret = 0;
	if (ac >= 2)
	{
		i = 0;
		while (++i < ac)
		{
			if ((fd[i - 1] = open(av[i], O_RDONLY)) < 0)
				if ((fd[i - 1] = atoi(av[i])) < 0)
					return (-1);
		}
	}
	j = 0;
	ct = 0;
	while (j < ac - 1)
	{
		j = 0;
		for (i = 0; i < ac - 1; i++)
		{
			if (fd[i] > -1)
			{
				t = get_next_line(fd[i], &ret);
				doprint(t, fd[i], &ret, ct++);
				if (t <= 0)
					fd[i] = -1;
			}
			else
				j++;
		}
	}
	return (1);
}
