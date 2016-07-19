/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_dijkstra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 14:22:37 by aribeiro          #+#    #+#             */
/*   Updated: 2016/04/21 20:04:39 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	pathfinding_p2(t_lem *s, int i, int mini)
{
	while (i < (s->count_room + 1))
	{
		if (s->tab[mini][i] != 0)
		{
			if ((s->v_tab[mini][0] + 1) < s->v_tab[i][0])
			{
				s->v_tab[i][0] = s->v_tab[mini][0] + 1;
				s->pr_tab[i] = mini;
			}
		}
		i++;
	}
}

void		lem_pathfinding(t_lem *s, int i, int k, int mini)
{
	lem_ini_v_tab(s);
	lem_ini_pr_tab(s);
	while (k++ < (s->count_room + 1))
	{
		mini = -1;
		i = 0;
		while (i < (s->count_room + 1))
		{
			if (s->v_tab[i][1] == 0 && mini == -1)
				mini = i;
			else if (s->v_tab[i][1] == 0 && s->v_tab[i][0] < s->v_tab[mini][0])
				mini = i;
			i++;
		}
		if (mini == -1)
			return ;
		s->v_tab[mini][1] = 1;
		i = 0;
		pathfinding_p2(s, i, mini);
	}
}

static void	lem_path_tab(t_lem *s, int end, int line, int *i)
{
	if (s->pr_tab[end] != -1)
		lem_path_tab(s, s->pr_tab[end], line, i);
	s->pa_tab[line][*i] = end;
	s->v_tab[end][1] = -1;
	s->pa_tab[line][0] = *i;
	*i += 1;
}

static void	norme(t_lem *s, t_room **r, int cas)
{
	if (cas == 1)
	{
		lem_pathfinding(s, 0, 0, 0);
		if (s->pr_tab[s->id_end] == -1)
		{
			if (!(s->flags & FIND_PATH))
				lem_display_errors("ERROR : no path\n", s, r);
			else
				ft_set_bit(&(s->flags), STOP_FIND_PATH);
		}
	}
	else if (cas == 2)
	{
		lem_free_tab(s);
		lem_free_visited_tab(s);
		lem_free_predecessor_tab(s);
	}
}

void		lem_dijkstra(t_lem *s, t_room **r)
{
	int line;
	int i;

	line = 0;
	while (!(s->flags & STOP_FIND_PATH))
	{
		norme(s, r, 1);
		if (s->pr_tab[s->id_end] != -1)
		{
			s->count_path++;
			if (s->flags & FIND_PATH)
				line++;
			i = 1;
			lem_path_tab(s, s->id_end, line, &i);
			if (!(s->flags & FIND_PATH))
				ft_set_bit(&(s->flags), FIND_PATH);
			if (s->pr_tab[s->id_end] == s->id_start)
			{
				s->tab[s->id_end][s->id_start] = 0;
				s->tab[s->id_start][s->id_end] = 0;
			}
		}
	}
	norme(s, r, 2);
}
