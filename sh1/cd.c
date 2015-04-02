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
	char		*tmp;

	if ((((ft_strcmp(k->cmd[0], "cd") == 0 && k->cmd[1] == NULL)) ||
		((ft_strcmp(k->cmd[0], "cd") == 0 && ft_strcmp(k->cmd[1], "~") == 0))))
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
		k->env[ft_search(k->env, "OLDPWD")] = ft_strjoin("OLDPWD=", k->pwd);
		ft_str_swap(k->pwd, k->oldpwd);
	}
	else if ((ft_strcmp(k->cmd[0], "cd") == 0 &&
		ft_strcmp(k->cmd[1], "/") == 0))
	{	
		// printf("%s\n", k->pwd);
		k->oldpwd = k->pwd;
		// printf("%s\n", k->oldpwd);
		k->env[ft_search(k->env, "OLDPWD")] = ft_strjoin("OLDPWD=", k->oldpwd);
		chdir("/");
		k->env[ft_search(k->env, "PWD")] = "PWD=/";
		k->pwd = "/";
	}
}

void		cd(t_fat *k)
{
	char	*buf;
	char 	*tmp;
	int		x;

		// printf("pwd = %s\n", k->pwd);
		// printf("old = %s\n", k->oldpwd);

	if (k->cmd[1] && ft_strcmp(k->cmd[1], "-") != 0 &&
		ft_strcmp(k->cmd[1], "~") != 0 && 
		ft_strcmp(k->cmd[1], "/") != 0 )
	{
		// x = ft_strlen(k->env[ft_search(k->env, "PWD")]) + ft_strlen(k->cmd[1]);
		// puts("1");
		// printf("%d\n", x);
		if (access(k->cmd[1], F_OK) == 0 && access(k->cmd[1], X_OK) == 0)
		{
			// puts("1");
			// ft_strcpy(k->oldpwd, k->pwd); 
			k->oldpwd = k->pwd;
			// puts("2");
			chdir(k->cmd[1]);
			// puts("3");
			buf = ft_memalloc(x);
			// puts("malloc tmp");
			// tmp = ft_memalloc(x + 15);
			// if (!tmp)
			// {
			// 	puts("malloc error");
			// 	return ;
			// }
			// tmp = "PWD=";

			// puts("malloc tmp done");
			
			// puts("4");
			// printf("%s\n", buf);
			buf = getcwd(buf, MAXPATHLEN);
			// printf("%s\n", buf);
			// tmp = ft_strjoin("PWD=", buf);
			// printf("tmp = %s\n", tmp);
			// k->env[ft_search(k->env, "PWD")] = ft_strdup(tmp);
			// k->env[ft_search(k->env, "PWD")] = ft_strjoin("PWD=", buf);
			// tmp = ft_str
			// k->env[ft_search(k->env, "PWD")] = tmp;
			// puts("5");
			// k->env[ft_search(k->env, "OLDPWD")] =
			// ft_strjoin("OLDPWD=", k->oldpwd);
			// puts("6");
			// printf("%s\n", buf);
			// ft_strcpy(k->pwd, buf);
			k->pwd = buf;
			// puts("7");
			// free(buf);
			// free(tmp);
		}
		else
			cd_rror(k);
	}
	else
		cd_tilde_minus(k);
	// printf("pwd = %s\n", k->pwd);
	// printf("old = %s\n", k->oldpwd);
}
