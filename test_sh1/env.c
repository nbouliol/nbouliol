/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouliol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 16:16:02 by nbouliol          #+#    #+#             */
/*   Updated: 2015/03/24 16:16:08 by nbouliol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int			mini_set(char *str, char **nenv, char *str2, char **env)
{
	if (ft_search(env, str2) >= 0)
	{
		if (ft_strstr(str, "=") == NULL)
			str = ft_strcat(str, "=");
		ft_strcpy(nenv[ft_search(env, str2)], str);
		return (1);
	}
	return (0);
}

char		**ft_setenv(char **env, char *str)
{
	int		i;
	char	**nenv;
	char	*tmp;
	char	str2[5];

	if (!str)
	{
		ft_putstr_fd("\033[0;93msetenv error : need some"
			" argument to setenv\033[0m\n", 2);
		return (env);
	}
	ft_strncpy(str2, str, 4);
	i = env_cnt(env);
	nenv = env_cpy(env);
	if (mini_set(str, nenv, str2, env) == 0)
	{
		str = (ft_strstr(str, "=") == NULL) ? ft_strcat(str, "=") : str;
		tmp = nenv[i];
		nenv[i] = str;
		nenv[i + 1] = tmp;
		env[i] = str;
		ft_str_swap(nenv[i], nenv[i - 1]);
		nenv[i + 1] = NULL;
	}
	return (nenv);
}

void		ft_unsetenv(t_fat *k, char *str)
{
	int		l;

	l = ft_search(k->env, str);
	if (l >= 0)
	{
		delete_line(k, str);
		resize_tab(k);
	}
}

void		ft_putenv(char **env)
{
	int	y;

	y = 0;
	while (env[y] != NULL)
	{
		ft_putstr(env[y]);
		ft_putchar('\n');
		y++;
	}
}
