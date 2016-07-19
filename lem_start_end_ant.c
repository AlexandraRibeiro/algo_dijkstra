/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_start_end_ant.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 19:22:31 by aribeiro          #+#    #+#             */
/*   Updated: 2016/04/21 21:52:54 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lem_check_start(t_lem *s, t_room **r)
{
	if (s->line[0] == 'L')
		lem_display_errors("ERROR : no valid room\n", s, r);
	if (s->flags & FIND_START)
	{
		if (s->line[0] == '#')
			lem_display_errors("ERROR : no valid line after ##start\n", s, r);
		else
			lem_check_room(s, r, 1);
	}
	else if (!(s->flags & FIND_START))
	{
		if (s->line[0] == '#')
			return ;
		else
			ft_set_bit(&(s->flags), FIND_START);
	}
}

void	lem_check_end(t_lem *s, t_room **r)
{
	if (s->line[0] == 'L')
		lem_display_errors("ERROR : no valid room\n", s, r);
	if (s->flags & FIND_END)
	{
		if (s->line[0] == '#')
			lem_display_errors("ERROR : no valid line after ##end\n", s, r);
		else
			lem_check_room(s, r, 2);
	}
	else if (!(s->flags & FIND_END))
	{
		if (s->line[0] == '#')
			return ;
		else
			ft_set_bit(&(s->flags), FIND_END);
	}
}

void	lem_check_ant(t_lem *s, t_room **r)
{
	long long int a;

	if (s->line[0] == '0' || (ft_strcmp("##start", s->line) == 0)
						|| (ft_strcmp("##end", s->line) == 0))
		lem_display_errors("ERROR : no ant\n", s, r);
	if (s->line[0] == '#')
		return ;
	else if (s->line[0] < '1' || s->line[0] > '9')
		lem_display_errors("ERROR : no valid line before ant\n", s, r);
	else
	{
		a = lem_atoi(s->line, s);
		if (a == -2147483650)
			lem_display_errors("ERROR : no valid ant\n", s, r);
		s->ant = (unsigned int)a;
		ft_set_bit(&(s->flags), VALID_ANT);
		return ;
	}
}
