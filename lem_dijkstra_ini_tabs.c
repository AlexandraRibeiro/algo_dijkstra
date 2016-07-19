/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_dijkstra_ini_tabs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 15:04:22 by aribeiro          #+#    #+#             */
/*   Updated: 2016/04/12 16:06:47 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** s->pr_tab[i++] : predecessors is the index of the room that comes right
** before i int the path from start to i
*/

void	lem_ini_pr_tab(t_lem *s)
{
	int i;

	i = 0;
	while (i < (s->count_room + 1))
	{
		s->pr_tab[i] = -1;
		i++;
	}
}

/*
** s->we_tab[i][0] : length of the path between start and room i
** s->we_tab[i][1] : visited ? 1 = Y, 0 = N
** s->v_tab[i][1] == -1 : removes the room visited to find other paths
*/

void	lem_ini_v_tab(t_lem *s)
{
	int i;

	i = 0;
	if (s->flags & FIND_PATH)
	{
		while (i < (s->count_room + 1))
		{
			s->v_tab[i][0] = 65000;
			i++;
		}
		s->v_tab[s->id_start][0] = 0;
		i = 0;
		while (i < (s->count_room + 1))
		{
			if (s->v_tab[i][1] == 1)
				s->v_tab[i][1] = 0;
			i++;
		}
	}
	s->v_tab[s->id_start][1] = 0;
	s->v_tab[s->id_end][1] = 0;
}
