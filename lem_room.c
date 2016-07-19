/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 19:14:33 by aribeiro          #+#    #+#             */
/*   Updated: 2016/04/22 14:23:16 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		valid_xy(t_lem *s, int i, int j)
{
	int				sp;

	sp = 0;
	s->stock = ft_strnew_exit(s->len);
	while (s->line[i] != '\0' && sp < 2)
	{
		if (s->line[i] == ' ')
		{
			if (j == 0 || ((s->p = lem_atoi(s->stock, s)) == -2147483650))
				return (1);
			ft_bzero(s->stock, s->len);
			j = 0;
			sp++;
		}
		else
		{
			s->stock[j] = s->line[i];
			j++;
		}
		i++;
	}
	if (sp != 1 || j == 0)
		return (1);
	return (0);
}

static int		valid_namep2(t_lem *s, int ret, int i)
{
	ret = valid_xy(s, i, 0);
	ft_memdel((void **)&(s->stock));
	if (ret == 1)
		ft_memdel((void **)&(s->n));
	return (ret);
}

static int		valid_name(t_lem *s)
{
	int	i;
	int	ret;

	i = 0;
	s->len = ft_strlen(s->line);
	if (s->len < 5)
		return (1);
	s->n = ft_strnew_exit(s->len);
	while (s->line[i] != ' ' && s->line[i] != '\0')
	{
		if (s->line[i] == '-')
		{
			ft_memdel((void **)&(s->n));
			return (1);
		}
		s->n[i] = s->line[i];
		i++;
	}
	if (s->line[i] == '\0')
	{
		ft_memdel((void **)&(s->n));
		return (1);
	}
	ret = valid_namep2(s, 0, ++i);
	return (ret);
}

static void		check_room_cas3(t_lem *s, t_room **r)
{
	if (s->line[0] == '#')
		return ;
	if (!(s->flags & FIND_TUBE))
	{
		if (valid_name(s) == 1)
		{
			if (lem_check_tube(s, r, 0, 0) == 1)
			{
				ft_set_bit(&(s->flags), STOP_READ);
				return ;
			}
			lem_create_tab(s);
			lem_fill_tab(s);
			ft_set_bit(&(s->flags), FIND_TUBE);
		}
		else
		{
			if (lem_create_list_room(s, r, s->n) == 1)
			{
				ft_set_bit(&(s->flags), STOP_READ);
				return ;
			}
		}
	}
}

/*
** cas == 1 > check start room
** cas == 2 > check end room
** cas == 3 > check other rooms, check if it's a tube
*/

void			lem_check_room(t_lem *s, t_room **r, int cas)
{
	if (cas == 1)
	{
		if (valid_name(s) == 1)
			lem_display_errors("ERROR : no valid start room\n", s, r);
		if (lem_create_list_room(s, r, s->n) == 1)
			lem_display_errors("ERROR : no valid start room (dup)\n", s, r);
		s->id_start = s->count_room - 1;
		ft_set_bit(&(s->flags), VALID_START);
	}
	else if (cas == 2)
	{
		if (valid_name(s) == 1)
			lem_display_errors("ERROR : no valid end room\n", s, r);
		if (lem_create_list_room(s, r, s->n) == 1)
			lem_display_errors("ERROR : no valid end room (dup)\n", s, r);
		s->id_end = s->count_room - 1;
		ft_set_bit(&(s->flags), VALID_END);
	}
	else if (cas == 3)
		check_room_cas3(s, r);
}
