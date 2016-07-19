/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_dijkstra_tabs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 15:03:54 by aribeiro          #+#    #+#             */
/*   Updated: 2016/04/21 20:06:20 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** s->pa_tab[i][0] : room counter for this path
** s->pa_tab[i][1++] : every rooms between start and end for this path
*/

static void	create_path_tab(t_lem *s)
{
	int i;
	int len;

	len = s->count_room + 1;
	s->pa_tab = (int **)ft_memalloc_exit(sizeof(int *) * len);
	i = 0;
	while (i < len)
	{
		s->pa_tab[i] = (int *)ft_memalloc_exit(sizeof(int) * len);
		i++;
	}
}

/*
** s->pr_tab[i++] : predecessors is the index of the room that comes right
** before i int the path from start to i
*/

static void	create_predecessor_tab(t_lem *s)
{
	int i;

	s->pr_tab = (int *)ft_memalloc_exit(sizeof(int) * (s->count_room + 1));
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
*/

static void	create_visited_tab(t_lem *s)
{
	int i;

	s->v_tab = (int **)ft_memalloc_exit(sizeof(int *) * (s->count_room + 1));
	i = 0;
	while (i < (s->count_room + 1))
	{
		s->v_tab[i] = (int *)ft_memalloc_exit(sizeof(int) * 2);
		i++;
	}
	i = 0;
	while (i < (s->count_room + 1))
	{
		s->v_tab[i][0] = 65000;
		i++;
	}
	s->v_tab[s->id_start][0] = 0;
}

void		lem_dijkstra_tabs(t_lem *s)
{
	create_visited_tab(s);
	create_predecessor_tab(s);
	create_path_tab(s);
}
