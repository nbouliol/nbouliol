/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouliol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 15:41:23 by nbouliol          #+#    #+#             */
/*   Updated: 2015/03/24 15:41:25 by nbouliol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void		get_old_pwd(t_fat *k)
{
	char	*zeub;
	char	**old_pwd;

	zeub = ft_memalloc(ft_strlen(k->env[ft_search(k->env, "OLDPWD")]));
	old_pwd = ft_memalloc(ft_strlen(k->env[ft_search(k->env, "OLDPWD")]));
	zeub = k->env[ft_search(k->env, "OLDPWD")];
	old_pwd = ft_strsplit(zeub, '=');
	k->oldpwd = old_pwd[1];
}

void		get_pwd(t_fat *k)
{
	char	*teub;
	char	**pwd;

	teub = ft_memalloc(ft_strlen(k->env[ft_search(k->env, "PWD")]));
	pwd = ft_memalloc(ft_strlen(k->env[ft_search(k->env, "PWD")]));
	teub = k->env[ft_search(k->env, "PWD")];
	pwd = ft_strsplit(teub, '=');
	k->pwd = pwd[1];
}

void		cd_rror(t_fat *k)
{
	if (access(k->cmd[1], F_OK) == -1)
	{
		ft_putstr_fd("\033[0;93mcd: no such file or directory: \033[0m", 2);
		ft_putstr_fd(k->cmd[1], 2);
		ft_putchar_fd('\n', 2);
	}
	else if (access(k->cmd[1], X_OK) == -1)
	{
		ft_putstr_fd("\033[0;93mcd: permission denied: \033[0m", 2);
		ft_putstr_fd(k->cmd[1], 2);
		ft_putchar_fd('\n', 2);
	}
}

void		cd_tilde_minus(t_fat *k)
{
	if (((ft_strcmp(k->cmd[0], "cd") == 0 && k->cmd[1] == NULL)) ||
		((ft_strcmp(k->cmd[0], "cd") == 0 && ft_strcmp(k->cmd[1], "~") == 0)))
	{
		k->oldpwd = k->pwd;
		k->env[ft_search(k->env, "OLDPWD")] = ft_strjoin("OLDPWD=", k->oldpwd);
		chdir(get_home(k->env));
		k->env[ft_search(k->env, "PWD")] = ft_strjoin("PWD=", get_home(k->env));
		k->pwd = get_home(k->env);
	}
	else if ((ft_strcmp(k->cmd[0], "cd") == 0 &&
		ft_strcmp(k->cmd[1], "-") == 0))
	{
		chdir(k->oldpwd);
		ft_putstr(k->oldpwd);
		ft_putchar('\n');
		k->env[ft_search(k->env, "PWD")] = ft_strjoin("PWD=", k->oldpwd);
		k->env[ft_search(k->env, "OLDPWD")] = ft_strjoin("OLDPWD=", k->oldpwd);
		k->pwd = k->oldpwd;
	}
}

void		cd(t_fat *k)
{
	char	*buf;
	int		x;

	if (k->cmd[1] && ft_strcmp(k->cmd[1], "-") != 0 &&
		ft_strcmp(k->cmd[1], "~") != 0)
	{
		if (access(k->cmd[1], F_OK) == 0 && access(k->cmd[1], X_OK) == 0)
		{
			k->oldpwd = k->pwd;
			chdir(k->cmd[1]);
			buf = ft_memalloc(MAXPATHLEN);
			buf = getcwd(buf, MAXPATHLEN);
			k->env[ft_search(k->env, "PWD")] = ft_strjoin("PWD=", buf);
			k->env[ft_search(k->env, "OLDPWD")] =
			ft_strjoin("OLDPWD=", k->oldpwd);
			k->pwd = buf;
		}
		else
			cd_rror(k);
	}
	else
		cd_tilde_minus(k);
}
