/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 13:37:42 by aribeiro          #+#    #+#             */
/*   Updated: 2016/04/21 20:45:20 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lem_strjoin_ter(t_lem *s, char c)
{
	char	*tmp;
	int		len;
	int		i;

	i = 0;
	if (s->line != NULL)
	{
		len = ft_strlen(s->line) + 1;
		if (s->file != NULL)
			len += ft_strlen(s->file) + 1;
		tmp = ft_strnew_exit(len);
		if (s->file != NULL)
		{
			while (s->file[i] != '\0')
			{
				tmp[i] = s->file[i];
				i++;
			}
			tmp[i] = c;
		}
		tmp = ft_strcat(tmp, s->line);
		if (s->file != NULL)
			free(s->file);
		s->file = tmp;
	}
}
