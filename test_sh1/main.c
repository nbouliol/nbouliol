/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouliol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 17:04:52 by nbouliol          #+#    #+#             */
/*   Updated: 2015/03/24 17:04:54 by nbouliol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int		main(int ar, char **av, char **envp)
{
	t_fat	*k;

	if (!envp || !*envp)
	{
		ft_putstr_fd("\033[1;91mNo environment!\n\033[0m", 2);
		return (-1);
	}
	k = (t_fat*)malloc(sizeof(t_fat));
	ft_path_env(envp, k);
	k->env = env_cpy(envp);
	get_pwd(k);
	k->env[ft_search(k->env, "OLDPWD")] = ft_strjoin("OLDPWD=", k->pwd);
	k->oldpwd = k->pwd;
	ft_lect(k, envp);
	return (0);
}
