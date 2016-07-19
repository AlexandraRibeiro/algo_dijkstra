/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 14:05:11 by aribeiro          #+#    #+#             */
/*   Updated: 2016/04/18 13:32:30 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lst_free(t_file **stat, t_file *tmp, t_file *cpy, int cas)
{
	cpy = *stat;
	if (cas == 1)
	{
		if (tmp->buf != NULL)
			ft_memdel((void **)&(tmp->buf));
		while (*stat != tmp && cpy->next != tmp)
			cpy = cpy->next;
		cpy->next = tmp->next;
		if (*stat == tmp && cpy == *stat)
			*stat = (*stat)->next;
		free(tmp);
	}
	else if (cas == 2)
	{
		while (cpy != NULL)
		{
			if (cpy->buf != NULL)
				ft_memdel((void **)&(cpy->buf));
			tmp = cpy->next;
			free(cpy);
			cpy = tmp;
		}
		*stat = NULL;
	}
}

static int	ft_lst_create(t_file **stat, t_file **tmp, int const fd)
{
	t_file	*prev;

	if (((*tmp) = (t_file *)malloc(sizeof(t_file))) == NULL)
		return (-1);
	if (((*tmp)->buf = ft_strnew(BUFF_SIZE)) == NULL)
	{
		ft_memdel((void **)tmp);
		return (-1);
	}
	(*tmp)->fd = fd;
	(*tmp)->x = 0;
	(*tmp)->s2 = NULL;
	(*tmp)->next = NULL;
	if (*stat == NULL)
		*stat = *tmp;
	else
	{
		prev = *stat;
		while (prev->next != NULL)
			prev = prev->next;
		prev->next = *tmp;
	}
	return (1);
}

/*
** len = 0, for case without '\n'
** line 85 : x start of str, s1 end of str, buf adresse de str[0])
** line 96 : +1 going after '\n'
*/

static int	ft_send_line(t_file *tmp, char **line, char *s1)
{
	char	*s3;
	int		len;

	len = 0;
	if (s1 != NULL)
		len = (s1 - tmp->buf) - tmp->x;
	s3 = ft_strsub(tmp->buf, tmp->x, len);
	if (tmp->s2 != NULL && s3 != NULL)
	{
		*line = ft_strjoin(tmp->s2, s3);
		ft_memdel((void **)&(tmp->s2));
	}
	else if (s3 != NULL)
		*line = ft_strdup(s3);
	else
		return (-1);
	ft_memdel((void **)&s3);
	tmp->x = tmp->x + len + 1;
	if (tmp->x >= tmp->rd)
	{
		tmp->x = 0;
		ft_strclr(tmp->buf);
	}
	return (1);
}

static int	ft_read_copy(t_file *tmp, char **line)
{
	char	*s1;

	while (tmp)
	{
		if (tmp->x == 0)
			if ((tmp->rd = read(tmp->fd, tmp->buf, BUFF_SIZE)) < 1)
				if (tmp->s2 == NULL || tmp->rd == -1)
					return (tmp->rd);
		if ((s1 = ft_strchr((tmp->buf + tmp->x), '\n')) != NULL ||
								tmp->rd == 0)
			return (ft_send_line(tmp, line, s1));
		if (tmp->s2 != NULL)
		{
			s1 = ft_strjoin(tmp->s2, (tmp->buf + tmp->x));
			ft_memdel((void **)&(tmp->s2));
		}
		else
			s1 = ft_strdup(tmp->buf + tmp->x);
		if (s1 == NULL)
			return (-1);
		tmp->s2 = s1;
		ft_strclr(tmp->buf);
		tmp->x = 0;
	}
	return (-1);
}

/*
** line 144 bonus forced to free stat
*/

int			get_next_line(int const fd, char **line)
{
	static t_file	*stat;
	t_file			*tmp;
	int				e;

	if (fd < 0 && line == NULL && stat != NULL)
	{
		ft_lst_free(&stat, NULL, NULL, 2);
		return (-1);
	}
	if (fd < 0 || line == NULL)
		return (-1);
	tmp = stat;
	while (tmp != NULL && tmp->fd != fd)
		tmp = tmp->next;
	if (tmp == NULL && ft_lst_create(&stat, &tmp, fd) == -1)
		return (-1);
	e = ft_read_copy(tmp, line);
	if (e == -1 || e == 0)
		ft_lst_free(&stat, tmp, NULL, 1);
	return (e);
}
