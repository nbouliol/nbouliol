/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouliol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 16:40:25 by nbouliol          #+#    #+#             */
/*   Updated: 2014/12/08 16:49:42 by nbouliol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_line_cpy(char *str)
{
	size_t			i;
	size_t			j;
	char			*line;

	j = ft_strlen(str);
	line = ft_memalloc(j + 1);
	i = 0;
	while ((str[i] != '\n' && i <= j) || i == BUF)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	i = 0;
	return (line);
}

static char		*ft_clr_tmp(char *str)
{
	size_t			i;
	int				j;
	char			*new;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (NULL);
	new = ft_memalloc(ft_strlen(str) - (i - 1));
	if (str[i] == '\n')
	{
		i++;
		while (str[i] != '\0')
		{
			new[j] = str[i];
			j++;
			i++;
		}
	}
	return (new);
}

int				get_next_line(int const fd, char **line)
{
	static char		*tmp[255];
	char			sread[BUF + 1];
	int				rd;

	if (fd < 0 || (!line) || BUF <= 0)
		return (-1);
	if (!tmp[fd])
		tmp[fd] = ft_strnew(1);
	rd = 1;
	while (ft_strchr(tmp[fd], '\n') == NULL && rd > 0)
	{
		rd = read(fd, sread, BUF);
		if (rd == -1)
			return (-1);
		sread[rd] = '\0';
		if (!tmp[fd])
			tmp[fd] = sread;
		else
			tmp[fd] = ft_strjoin(tmp[fd], sread);
	}
	line[0] = ft_line_cpy(tmp[fd]);
	tmp[fd] = ft_clr_tmp(tmp[fd]);
	if (rd == 0 && tmp[fd] == NULL)
		return (0);
	return (1);
}
