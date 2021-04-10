/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:38:01 by ckasyc            #+#    #+#             */
/*   Updated: 2021/04/10 15:57:45 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

typedef struct	s_gnl
{
	char	buf[BUFFER_SIZE];
	int		pos;
	int		len;
	int		line_nb;
	int		fd;
}				t_gnl;
typedef struct	s_lst
{
	struct s_lst	*next;
	void			*content;
}				t_lst;
int				get_next_line(int fd, char **line);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
int				ft_strlen(char *str);

#endif
