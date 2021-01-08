/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 00:04:03 by ckasyc            #+#    #+#             */
/*   Updated: 2021/01/09 00:09:42 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

void	doprint(int out, char **str, int line)
{
	printf("%2i - [OUT %i] |%s|\n", line, out, *str);
	if (*str)
		free(*str);
	*str = NULL;
}

int main(int ac, char **av)
{
	char *ret;
	int fd;
	int t;
	int i;

	ret = 0;
	fd = 0;
	if (ac == 2)
		if ((fd = open(av[1], O_RDONLY)) < 0)
			return (-1);
	if (ac == 3)
		fd = atoi(av[2]);
	i = 0;
	while ((t = get_next_line(fd, &ret)) > 0)
		doprint(t, &ret, i++);
	doprint(t, &ret, i++);
	return (1);
}
