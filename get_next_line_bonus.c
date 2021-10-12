/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 09:34:48 by ckasyc            #+#    #+#             */
/*   Updated: 2021/10/12 12:22:29 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	init_struct(t_gnl *info, int fd)
{
	if (info->pos == -100)
	{
		info->pos = -2;
		info->fd = fd;
		info->len = -1;
		info->eof = 1;
	}
	info->written = 0;
}

char	*concat_str(char **str, char c)
{
	char	*ret;
	int		len;
	
	len = ft_strlen(*str);
	ret = (char*)malloc((len + 2) * sizeof(char));
	if (ret == NULL){
		free(*str);
		*str = NULL;
		return (NULL);
	}
	ret[0] = '\0';
	ft_strlcat(ret, *str, len + 1);
	ret[len] = c;
	ret[len + 1] = '\0';
	free(*str);
	*str = ret;
	return (ret);
}

int		read_file(t_gnl *inf, char **ret)
{
	while (inf->len != 0)
	{
		while (inf->pos >= 0 && inf->pos < inf->len 
			&& inf->str[inf->pos] != '\n' && inf->str[inf->pos] != '\0')
		{
			inf->written = 1;
			if (concat_str(ret, inf->str[inf->pos]) == NULL) 
				return (-1);
			inf->pos += 1;
		}
		if (inf->pos >= 0 && inf->pos < inf->len &&
			(inf->str[inf->pos] == '\n' || inf->str[inf->pos] == '\0'))
			return (1);
		if ((inf->len = read(inf->fd, inf->str, BUFFER_SIZE)) < 0)
			inf->len = 0;
		if (inf->len < BUFFER_SIZE)
			inf->eof = 0;
		inf->pos = 0;
	}
	return (0);
}

int		read_file2(t_gnl *inf, char **ret)
{
	while ((inf->len != 0 || inf->pos < inf->len))
	{
		if (inf->pos >= 0)
		{
			inf->written = 1;
			while (inf->pos < inf->len)
			{
				if (inf->str[(inf->pos)] == '\n' || inf->str[(inf->pos)] == '\0')
				{
					inf->pos += 1;
					return (1);
				}
				if (concat_str(ret, inf->str[inf->pos]) == NULL) 
					return (-1);
				inf->pos += 1;
			}
		}
		if ((inf->len = read(inf->fd, inf->str, BUFFER_SIZE)) < 0)
			inf->len = 0;
		if (inf->len < BUFFER_SIZE)
			inf->eof = -1;
		inf->pos = 0;
	}
	return (0);
}

char*	get_next_line(int fd)
{
	static t_gnl	info = { .pos = -100};
	char			*ret;
	int				val;

	init_struct(&info, fd);
	if (fd < 0 || BUFFER_SIZE <= 0 || fd != info.fd)
		return (NULL);
	ret = (char*)malloc(sizeof(char));
	if (ret == NULL)
		return (NULL);
	ret[0] = '\0';
	val = read_file(&info, &ret);
	if (val == 1)
		if (concat_str(&ret, info.str[info.pos++]) == NULL) 
			return (NULL);
	if (val == 0 && info.eof == 0 && info.pos >= info.len && info.written == 0)
		val = -1;
	if (val != -1)
		return (ret);
	free(ret);
	return (NULL);
}
