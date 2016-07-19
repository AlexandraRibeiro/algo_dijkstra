/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 18:13:51 by aribeiro          #+#    #+#             */
/*   Updated: 2016/04/22 13:41:03 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	verif_duplicate(t_room **r, char *n)
{
	t_room *tmp;

	tmp = *r;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->name, n) == 0)
		{
			if (n != NULL)
				ft_memdel((void **)&n);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int			lem_create_list_room(t_lem *s, t_room **r, char *n)
{
	t_room *tmp;
	t_room *mv;

	if (verif_duplicate(r, n) == 1)
		return (1);
	if ((tmp = (t_room *)malloc(sizeof(t_room))) == NULL)
		exit(1);
	tmp->name = n;
	tmp->index = s->count_room;
	if (*r == NULL)
	{
		*r = tmp;
		tmp->next = NULL;
	}
	else
	{
		mv = *r;
		while (mv->next != NULL)
			mv = mv->next;
		mv->next = tmp;
		tmp->next = NULL;
	}
	s->count_room++;
	return (0);
}

void		lem_free_list_room(t_lem *s, t_room **r)
{
	t_room *tmp;
	t_room *cpy;

	if (*r != NULL)
	{
		tmp = *r;
		while (tmp != NULL)
		{
			if (tmp->name != NULL)
				ft_memdel((void **)&(tmp->name));
			cpy = tmp;
			tmp = tmp->next;
			free(cpy);
		}
		*r = NULL;
	}
	s->count_room = 0;
}
