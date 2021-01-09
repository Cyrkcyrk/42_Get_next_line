/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 22:12:04 by ckasyc            #+#    #+#             */
/*   Updated: 2021/01/09 20:56:53 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		lst_pushback(t_lst **ancre, void *c)
{
	t_lst *new;
	t_lst *tmp;

	if (!(new = malloc(sizeof(t_lst))))
		return (0);
	new->next = NULL;
	new->content = c;
	if (!*ancre)
		*ancre = new;
	else
	{
		tmp = *ancre;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (1);
}

void	ft_lstclear(t_lst **lst, void (*del)(void*))
{
	t_lst *prev;
	t_lst *maillon;

	maillon = *lst;
	while (maillon != NULL)
	{
		prev = maillon;
		maillon = maillon->next;
		(*del)(prev->content);
		free(prev);
	}
	*lst = NULL;
}

char	*lst_to_str(t_lst *ancre)
{
	int		i;
	t_lst	*tmp;
	char	*ret;

	tmp = ancre;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	if (!(ret = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = -1;
	tmp = ancre;
	while (tmp)
	{
		ret[++i] = *((char*)(tmp->content));
		tmp = tmp->next;
	}
	ret[i + 1] = '\0';
	return (ret);
}
