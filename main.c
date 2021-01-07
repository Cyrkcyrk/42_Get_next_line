/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 00:04:03 by ckasyc            #+#    #+#             */
/*   Updated: 2021/01/07 23:45:15 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

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
	i = 0;
	while ((t = get_next_line(fd, &ret)) > 0)
	{
		printf("%2d - %d: %s\n", i, t, ret);
		if (ret)
			free(ret);
		i++;
	}
	if (t == -1)
		printf("ERROR - %d\n", i);
	else
		printf("%2d - %d: %s\n", i, t, ret);
	if (ret)
		free(ret);
	return (1);
}
