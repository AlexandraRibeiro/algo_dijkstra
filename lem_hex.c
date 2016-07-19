/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 13:50:49 by aribeiro          #+#    #+#             */
/*   Updated: 2016/04/21 20:11:28 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** check if it's faster to go through multi path
*/

static unsigned int	multipath(t_lem *s, int t)
{
	int i;
	int l1;
	int l2;
	int l3;

	i = 0;
	l1 = (s->pa_tab[t][0] - 1) - 1;
	l2 = 0;
	while (i < t)
	{
		l3 = l1 - (s->pa_tab[i][0] - 1);
		if (l3 >= 0)
			l2 += l3;
		i++;
	}
	return ((unsigned int)l2);
}

/*
** Don't touch column 0
*/

static void			ant_shift(t_lem *s)
{
	int l;
	int c;

	l = 0;
	if (s->flags & FIRST_PASS)
	{
		ft_reset_bit(&(s->flags), FIRST_PASS);
		return ;
	}
	s->count_lap++;
	while (l < s->count_path)
	{
		c = s->pa_tab[l][0];
		s->hex_tab[l][1] = 0;
		while (c > 1)
		{
			s->hex_tab[l][c] = s->hex_tab[l][c - 1];
			c--;
		}
		l++;
	}
}

/*
** s->t = nb used path
** s->hex[s->t][0] : if path is not use = 0, else = 1 (for option)
*/

void				lem_hex(t_lem *s, t_room **r)
{
	unsigned int a;

	a = 0;
	lem_create_hex_tab(s);
	while (lem_empty_hex_tab(s) == 1)
	{
		ant_shift(s);
		s->t = 0;
		while (a < s->ant && s->t < s->count_path)
		{
			if ((s->t > 0 && multipath(s, s->t) < s->ant - a - 1) || s->t == 0)
				s->hex_tab[s->t][2] = ++a;
			s->t++;
		}
		if (lem_empty_hex_tab(s) == 1)
		{
			lem_display_final(s, r);
			ft_printf("\n");
			if (s->flags & OPTION_SHOW)
				lem_display_show(s, r, 0, 2);
		}
	}
	if (lem_empty_hex_tab(s) == 0)
		ft_set_bit(&(s->flags), PRINT_END);
}
