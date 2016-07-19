/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 15:20:00 by aribeiro          #+#    #+#             */
/*   Updated: 2016/04/21 20:43:06 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lem_fill_tab(t_lem *s)
{
	s->tab[s->index1][s->index2] = 1;
	s->tab[s->index2][s->index1] = 1;
}

void	lem_create_tab(t_lem *s)
{
	int	i;

	s->tab = (int **)ft_memalloc_exit(sizeof(int *) * (s->count_room + 1));
	i = 0;
	while (i < (s->count_room + 1))
	{
		s->tab[i] = (int *)ft_memalloc_exit(sizeof(int) * (s->count_room + 1));
		i++;
	}
}

void	lem_free_tab(t_lem *s)
{
	int i;

	i = 0;
	if (s->tab != NULL)
	{
		while (i < (s->count_room + 1))
		{
			if (s->tab[i] != NULL)
				free(s->tab[i]);
			i++;
		}
		if (s->tab != NULL)
			ft_memdel((void **)&(s->tab));
	}
}
