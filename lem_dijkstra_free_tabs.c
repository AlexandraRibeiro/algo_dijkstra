/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_dijkstra_free_tabs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 15:08:58 by aribeiro          #+#    #+#             */
/*   Updated: 2016/04/14 15:26:01 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** s->pa_tab[i][0] : room counter for this path
** s->pa_tab[i][1++] : every rooms between start and end for this path
*/

void	lem_free_path_tab(t_lem *s)
{
	int i;

	i = 0;
	while (i < (s->count_room + 1))
	{
		if (s->pa_tab[i] != NULL)
			free(s->pa_tab[i]);
		i++;
	}
	if (s->pa_tab != NULL)
		ft_memdel((void **)&(s->pa_tab));
}

/*
** s->pr_tab[i++] : predecessors is the index of the room that comes right
** before i int the path from start to i
*/

void	lem_free_predecessor_tab(t_lem *s)
{
	if (s->pr_tab != NULL)
		ft_memdel((void **)&(s->pr_tab));
}

/*
** s->we_tab[i][0] : length of the path between start and room i
** s->we_tab[i][1] : visited ? 1 = Y, 0 = N
*/

void	lem_free_visited_tab(t_lem *s)
{
	int i;

	i = 0;
	while (i < (s->count_room + 1))
	{
		if (s->v_tab[i] != NULL)
			free(s->v_tab[i]);
		i++;
	}
	if (s->v_tab != NULL)
		ft_memdel((void **)&(s->v_tab));
}
