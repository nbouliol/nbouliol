/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouliol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 15:48:23 by nbouliol          #+#    #+#             */
/*   Updated: 2015/03/24 15:48:25 by nbouliol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char		*ft_check(t_fat *k)
{
	int			i;
	char		*str;
	int			test;

	i = 0;
	if (ft_strcmp(k->cmd[0], "env") != 0)
	{
		while (k->path[i])
		{
			str = ft_strjoin(k->path[i], k->cmd[0]);
			test = access(str, X_OK);
			if (test == 0)
				return (str);
			i++;
		}
	}
	if (((ft_strnequ(k->cmd[0], ".", 1) == 1) ||
		(ft_strnequ(k->cmd[0], "/", 1) == 1)) &&
		access(k->cmd[0], X_OK) == 0)
		return (k->cmd[0]);
	return (NULL);
}

int			ft_mini_check(t_fat *k)
{
	if (ft_strcmp(k->cmd[0], "exit") == 0 && k->cmd[0])
	{
		if (!k->cmd[1])
			exit(0);
		else
			exit(ft_atoi(k->cmd[1]));
	}
	else if (ft_strcmp(k->cmd[0], "cd") == 0)
	{
		cd(k);
		return (2);
	}
	return (0);
}

int			ft_check2(t_fat *k)
{
	if (ft_mini_check(k) == 2)
		return (2);
	if (ft_strcmp(k->cmd[0], "setenv") == 0)
	{
		ft_setenv(k->env, k->cmd[1]);
		return (2);
	}
	else if (ft_strcmp(k->cmd[0], "env") == 0 && !k->cmd[1])
	{
		ft_putenv(k->env);
		return (2);
	}
	else if (ft_strcmp(k->cmd[0], "env") == 0 && k->cmd[1])
	{
		error(k->cmd[1]);
		return (2);
	}
	else if (ft_strcmp(k->cmd[0], "unsetenv") == 0 && k->cmd[1])
	{
		ft_unsetenv(k, k->cmd[1]);
		return (2);
	}
	return (0);
}
