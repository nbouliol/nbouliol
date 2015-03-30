/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouliol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 15:31:14 by nbouliol          #+#    #+#             */
/*   Updated: 2015/03/24 15:31:23 by nbouliol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int			ft_search(char **env, char *keyword)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strnequ(env[i], keyword, ft_strlen(keyword)) == 1)
			return (i);
		i++;
	}
	return (-1);
}

void		ft_path_env(char **env, t_fat *k)
{
	char		*zob;
	char		*tmp;
	char		**paths;
	int			i;
	int			j;

	i = 0;
	j = 0;
	zob = ft_memalloc(ft_strlen(env[ft_search(env, "PATH")]));
	tmp = ft_memalloc(ft_strlen(env[ft_search(env, "PATH")]));
	paths = malloc_char(paths, 20, 5);
	zob = env[ft_search(env, "PATH")];
	while (zob[i] != '/')
		i++;
	while (zob[i] != '\0')
		tmp[j++] = zob[i++];
	tmp[j++] = '\0';
	paths = ft_strsplit(tmp, ':');
	i = 0;
	while (paths[i])
	{
		paths[i] = ft_strjoin(paths[i], "/");
		i++;
	}
	k->path = paths;
}

char		*get_home(char **env)
{
	char	*prout;
	char	**home_path;

	prout = ft_memalloc(ft_strlen(env[ft_search(env, "HOME")]));
	home_path = ft_memalloc(ft_strlen(env[ft_search(env, "HOME")]));
	prout = env[ft_search(env, "HOME")];
	home_path = ft_strsplit(prout, '=');
	return (home_path[1]);
}

char		**malloc_char(char **tab, int x, int y)
{
	int		i;

	i = 0;
	tab = (char **)malloc(sizeof(char *) * y);
	if (!tab)
		return (NULL);
	while (i < y)
	{
		tab[i] = (char *)malloc(sizeof(char) * x);
		if (!tab[i])
			return (NULL);
		i++;
	}
	return (tab);
}

void		ft_str_swap(char *a, char *b)
{
	char		*tmp;

	if (!a || !b)
		return ;
	tmp = a;
	a = b;
	b = tmp;
}
