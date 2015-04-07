/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouliol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 16:24:27 by nbouliol          #+#    #+#             */
/*   Updated: 2015/03/24 16:24:29 by nbouliol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int			env_cnt(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

char		**env_cpy(char **env)
{
	char	**env2;
	char	*tmp;
	int		y;

	y = 0;
	env2 = (char **)malloc(sizeof(char *) * (env_cnt(env) + 10));
	while (env[y])
	{
		env2[y] = (char *)malloc(sizeof(char) * (int)ft_strlen(env[y] + 1));
		tmp = env[y];
		env2[y] = tmp;
		y++;
	}
	return (env2);
}

void		delete_line(t_fat *k, char *key)
{
	int		index;
	int		i;

	index = 0;
	while (k->env[index])
	{
		i = 0;
		while (k->env[i] && key[i] && key[i] == k->env[index][i])
			i++;
		if (k->env[index][i] == '=')
			k->env[index] = "";
		index++;
	}
}

void		resize_tab(t_fat *k)
{
	int		i;
	int		j;
	int		len;
	char	**sized_env;

	i = 0;
	j = 0;
	len = env_cnt(k->env);
	if (!(sized_env = (char **)malloc(sizeof(char *) * (len))))
		return ;
	while (i < len)
	{
		if (ft_strcmp(k->env[i], "") == 0)
			i++;
		else
		{
			sized_env[j] = k->env[i];
			j++;
			i++;
		}
	}
	sized_env[--i] = NULL;
	k->env = sized_env;
}

void		error(char *str)
{
	ft_putstr_fd("\033[0;93mft_minishell1: command not found: \033[0m", 2);
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
}
