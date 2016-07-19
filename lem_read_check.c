/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_read_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 11:36:17 by aribeiro          #+#    #+#             */
/*   Updated: 2016/04/22 14:17:22 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	analyse_line_part2(t_lem *s, t_room **r)
{
	if (s->flags & FIND_START && !(s->flags & VALID_START))
		lem_check_start(s, r);
	else if (s->flags & FIND_END && !(s->flags & VALID_END))
		lem_check_end(s, r);
	else if (!(s->flags & VALID_START) || !(s->flags & VALID_END))
	{
		if (ft_strcmp("##start", s->line) == 0)
			ft_set_bit(&(s->flags), FIND_START);
		else if (ft_strcmp("##end", s->line) == 0)
			ft_set_bit(&(s->flags), FIND_END);
		else
			lem_check_room(s, r, 3);
	}
	else
		lem_check_room(s, r, 3);
}

/*
** Expected order :
** ant : int
** room : name x y
** tube : name-name
*/

void		lem_analyse_line(t_lem *s, t_room **r)
{
	if (s->line[0] == '\0')
	{
		ft_set_bit(&(s->flags), STOP_READ);
		return ;
	}
	if (!(s->flags & VALID_ANT))
		lem_check_ant(s, r);
	else if (s->flags & VALID_ANT && !(s->flags & FIND_TUBE))
		analyse_line_part2(s, r);
	else if (s->flags & FIND_TUBE)
	{
		lem_verif_data(s, r);
		if (lem_check_tube(s, r, 0, 0) == 1)
		{
			ft_set_bit(&(s->flags), STOP_READ);
			return ;
		}
		lem_fill_tab(s);
	}
}

void		lem_verif_data(t_lem *s, t_room **r)
{
	if (!(s->flags & VALID_ANT))
	{
		if (s->c == 0)
			lem_display_errors("ERROR : empty file\n", s, r);
		else
			lem_display_errors("ERROR : no ant\n", s, r);
	}
	else if (!(s->flags & VALID_START) && !(s->flags & VALID_END))
		lem_display_errors("ERROR : no start & end rooms\n", s, r);
	else if (!(s->flags & VALID_START))
		lem_display_errors("ERROR : no start room\n", s, r);
	else if (!(s->flags & VALID_END))
		lem_display_errors("ERROR : no end room\n", s, r);
	else if (!(s->flags & FIND_TUBE))
		lem_display_errors("ERROR : no tube\n", s, r);
}

static void	verif_connection(t_lem *s, t_room **r)
{
	int k;

	k = 0;
	while (k < (s->count_room + 1) && s->tab[s->id_start][k] == 0)
		k++;
	if (k == (s->count_room + 1))
		lem_display_errors("ERROR : no connection with start room\n", s, r);
	k = 0;
	while (k < (s->count_room + 1) && s->tab[s->id_end][k] == 0)
		k++;
	if (k == (s->count_room + 1))
		lem_display_errors("ERROR : no connection with end room\n", s, r);
}

/*
** GNL:  ret == 0 end of file / ret == -1 error / ret == 1 one line read
*/

void		lem_read_check(int fd, t_lem *s, t_room **r)
{
	int ret;

	ret = 0;
	while (!(s->flags & STOP_READ))
	{
		if (s->line != NULL)
			ft_memdel((void **)&(s->line));
		ret = get_next_line(fd, &(s->line));
		if (ret == -1)
			lem_display_errors("ERROR : read\n", s, r);
		else if (ret == 1)
		{
			s->c++;
			lem_analyse_line(s, r);
			if (!(s->flags & STOP_READ))
				lem_strjoin_ter(s, '\n');
		}
		else if (ret == 0)
			break ;
	}
	lem_verif_data(s, r);
	ft_set_bit(&(s->flags), ERROR_MORE);
	verif_connection(s, r);
}
