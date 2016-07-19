/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 12:07:48 by aribeiro          #+#    #+#             */
/*   Updated: 2016/04/22 14:27:23 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	lem_ini_p2(t_lem *s)
{
	s->flags = 0;
	s->ret = 0;
	s->index1 = -1;
	s->index2 = -1;
	s->count_room = 0;
	s->count_path = 0;
	s->count_lap = 0;
	s->id_start = -1;
	s->id_end = -1;
	s->ant = 0;
	s->len = 0;
	s->p = 0;
}

static void	lem_ini_struct(t_lem *s)
{
	s->tab = NULL;
	s->v_tab = NULL;
	s->pr_tab = NULL;
	s->pa_tab = NULL;
	s->hex_tab = NULL;
	s->line = NULL;
	s->file = NULL;
	s->n = NULL;
	s->nt = NULL;
	s->stock = NULL;
	s->f = 0;
	s->l = 0;
	s->t = 0;
	s->c = 0;
	lem_ini_p2(s);
}

static void	verif_combi(int ac, char *a, t_lem *s)
{
	if (ac > 1 && ((ft_strcmp("-va", a) == 0) || (ft_strcmp("-av", a) == 0)))
	{
		ft_set_bit(&(s->flags), OPTION_ADD);
		ft_set_bit(&(s->flags), OPTION_VERBOSE);
	}
	if (ac > 1 && ((ft_strcmp("-vda", a) == 0) || (ft_strcmp("-vad", a) == 0)))
	{
		ft_set_bit(&(s->flags), OPTION_VERBOSE);
		ft_set_bit(&(s->flags), OPTION_ADD);
		ft_set_bit(&(s->flags), OPTION_DETAIL);
	}
	if (ac > 1 && ((ft_strcmp("-vdas", a) == 0)
											|| (ft_strcmp("-vads", a) == 0)))
	{
		ft_set_bit(&(s->flags), OPTION_VERBOSE);
		ft_set_bit(&(s->flags), OPTION_ADD);
		ft_set_bit(&(s->flags), OPTION_DETAIL);
		ft_set_bit(&(s->flags), OPTION_SHOW);
	}
}

static void	verif_bonus(int ac, char *a, t_lem *s)
{
	if (ac > 1 && (ft_strcmp("-h", a) == 0))
		lem_display_help();
	if (ac > 1 && (ft_strcmp("-v", a) == 0))
		ft_set_bit(&(s->flags), OPTION_VERBOSE);
	if (ac > 1 && (ft_strcmp("-a", a) == 0))
		ft_set_bit(&(s->flags), OPTION_ADD);
	if (ac > 1 && (ft_strcmp("-d", a) == 0))
		ft_set_bit(&(s->flags), OPTION_DETAIL);
	if (ac > 1 && (ft_strcmp("-s", a) == 0))
		ft_set_bit(&(s->flags), OPTION_SHOW);
	verif_combi(ac, a, s);
}

/*
** GNL if fd < 0 && line = NULL ---> free list
*/

int			main(int ac, char *av[])
{
	t_lem	s;
	t_room	*r;
	int		fd;

	fd = 0;
	r = NULL;
	lem_ini_struct(&s);
	if (ac > 1)
		verif_bonus(ac, av[1], &s);
	lem_read_check(fd, &s, &r);
	lem_dijkstra_tabs(&s);
	lem_dijkstra(&s, &r);
	lem_hex(&s, &r);
	if (s.flags & PRINT_END && s.flags & OPTION_ADD)
		lem_display_add(&s);
	if (s.flags & PRINT_END && s.flags & OPTION_DETAIL)
		lem_display_detail(&s, &r);
	lem_free(&s, &r);
	return (0);
}
