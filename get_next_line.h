/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 09:34:59 by ckasyc            #+#    #+#             */
/*   Updated: 2021/10/12 11:20:39 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_gnl {
	int		fd;
	char	str[BUFFER_SIZE + 1];
	int		pos;
	int		len;
	int		eof;
	int		written;
}				t_gnl;

int				ft_strlen(char *str);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

void			init_struct(t_gnl *info, int fd);
char			*concat_str(char **str, char c);
int				read_file(t_gnl *inf, char **ret);
char			*get_next_line(int fd);

#endif
