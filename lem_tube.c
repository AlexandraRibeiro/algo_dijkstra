/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_tube.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 19:16:18 by aribeiro          #+#    #+#             */
/*   Updated: 2016/04/21 20:47:45 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	search_index2(t_lem *s, t_room **r)
{
	t_room	*tmp;

	tmp = *r;
	while (tmp != NULL)
	{
		if (ft_strcmp(s->nt, tmp->name) == 0)
			break ;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return (1);
	else
	{
		s->index2 = tmp->index;
		ft_memdel((void **)&(s->nt));
	}
	return (0);
}

static int	search_index1(t_lem *s, t_room **r)
{
	t_room *tmp;

	tmp = *r;
	while (tmp != NULL)
	{
		if (ft_strcmp(s->nt, tmp->name) == 0)
			break ;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return (1);
	else
	{
		s->index1 = tmp->index;
		ft_bzero(s->nt, s->len);
	}
	return (0);
}

static int	check_tube2(t_lem *s, t_room **r, int *i, int *j)
{
	while (s->line[*i] != '\0' && s->t < 2)
	{
		if (s->line[*i] == '-')
		{
			if (*j == 0)
				return (1);
			if (search_index1(s, r) == 1)
				return (1);
			*j = 0;
			s->t++;
		}
		else
		{
			s->nt[*j] = s->line[*i];
			*j += 1;
		}
		*i += 1;
	}
	return (0);
}

int			lem_check_tube(t_lem *s, t_room **r, int i, int j)
{
	s->t = 0;
	s->len = ft_strlen(s->line);
	if (s->len < 3 || (ft_strchr(s->line, ' ') != NULL))
		return (1);
	s->nt = ft_strnew_exit(s->len);
	if (check_tube2(s, r, &i, &j) == 1)
	{
		ft_memdel((void **)&(s->nt));
		return (1);
	}
	if (s->t != 1 || j == 0)
	{
		ft_memdel((void **)&(s->nt));
		return (1);
	}
	else if (s->line[i] == '\0' && s->t == 1)
	{
		if (search_index2(s, r) == 1)
		{
			ft_memdel((void **)&(s->nt));
			return (1);
		}
	}
	return (0);
}
