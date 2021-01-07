/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:38:01 by ckasyc            #+#    #+#             */
/*   Updated: 2021/01/07 20:20:42 by ckasyc           ###   ########.fr       */
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
int				lst_pushback(t_lst **ancre, void *c);
char			*lst_to_str(t_lst *ancre);
void			ft_lstclear(t_lst **lst, void (*del)(void*));
#endif
