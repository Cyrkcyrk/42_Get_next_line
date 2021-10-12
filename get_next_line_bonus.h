/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 09:34:59 by ckasyc            #+#    #+#             */
/*   Updated: 2021/10/12 12:23:07 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# define MAX_FD 1024

typedef struct	s_gnl {
	int		fd;
	char	str[BUFFER_SIZE + 1];
	int		pos;
	int		len;
	int		eof;
	int		written;
}				t_gnl;

int				ft_strlen(char *str);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

void	init_struct(t_gnl *info, int fd);
char*	concat_str(char **str, char c);
int		read_file(t_gnl *inf, char **ret);
char*	get_next_line(int fd);

#endif
