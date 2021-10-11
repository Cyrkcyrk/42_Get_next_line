/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 09:34:48 by ckasyc            #+#    #+#             */
/*   Updated: 2021/10/11 09:34:51 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

char*	concat_str(char **str, char c)
{
	char	*ret;
	int		len;
	
	len = ft_strlen(*str);
	ret = (char*)malloc((len + 2) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	ret[0] = '\0';
	ft_strlcat(ret, *str, len + 1);
	ret[len] = c;
	ret[len + 1] = '\0';
	free(*str);
	*str = ret;
	// printf("%d - (%s) [%c|%d]\n", len, ret, c, c);
	return (ret);
}

char*	read_file(t_gnl *inf, char **ret)
{
	while (inf->len != 0)
	{
		// printf("INFO pos %d | len %d\n", inf->pos, inf->len);
		if (inf->pos >= -1 && inf->pos < inf->len)
		{
			while (inf->str[++(inf->pos)] != '\n' && inf->pos < inf->len)
				if (concat_str(ret, inf->str[inf->pos]) == NULL) 
				{
					// printf("LIGNE 48\n");
					return (NULL);
				}
			if (inf->str[(inf->pos)] == '\n' || (
				inf->pos < inf->len && inf->str[(inf->pos)] == '\0'))
			{
				// printf("STR[POS]: [%d|%c]\n", inf->str[(inf->pos)], inf->str[(inf->pos)]);
				return (*ret);
			}
		}
		if ((inf->len = read(inf->fd, inf->str, BUFFER_SIZE)) <= 0)
		{
			// printf("LIGNE 58\n");
			return (NULL);
		}
		inf->pos = -1;
	}
	// printf("end while\n");
	// printf("INFO pos %d | len %d\n", inf->pos, inf->len);
	return (NULL);
}


char*	get_next_line(int fd)
{
	static t_gnl	info = { .pos = -100};
	char			*ret;

	if (info.pos == -100)
	{
		info.pos = -2;
		info.fd = fd;
		info.len = -1;
		
	}
	if (fd < 0 || BUFFER_SIZE <= 0 || fd != info.fd)
		return (NULL);
	ret = (char*)malloc(sizeof(char));
	if (ret == NULL)
		return (NULL);
	ret[0] = '\0';
	return read_file(&info, &ret);
}