/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouliol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 17:09:32 by nbouliol          #+#    #+#             */
/*   Updated: 2015/03/24 17:09:42 by nbouliol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void		dick(void)
{
	ft_putstr("\033[0;40;32m&> \033[0m");
	ft_putstr("\033[0;31m 3=o \033[0m");
}

void		handle_signal(int signo)
{
	signo++;
	ft_putchar('\n');
	dick();
}

void		forking(t_fat *k, char **envp)
{
	pid_t		father;
	int			a;

	father = fork();
	if (father == 0)
	{
		if (access(k->cmd[0], X_OK) == 0)
			execve(k->cmd[0], k->cmd, envp);
		execve(ft_check(k), k->cmd, envp);
		if ((ft_check(k) == NULL && ft_check2(k) == 0) || (ft_strcmp(k->cmd[0], "/") == 0 && !k->cmd[1]))
		{
			error(k->cmd[0]);
			free(k->cmd[0]);
		}
	}
	else
		waitpid(father, &a, 0);
}

int			ft_lect(t_fat *k, char **envp)
{
	char		*line;
	char		**cmd;
	int			check_ret;

	signal(SIGINT, handle_signal);
	dick();
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strcmp(line, "\0") != 0)
		{
			line = epur_str(line);
			k->cmd = ft_strsplit(line, ' ');
			check_ret = ft_check2(k);
			if (check_ret == 0 && ft_check(k) != 0)
			{
				forking(k, envp);
			}
			else if (check_ret == 0 && ft_check(k) == 0)
				error(k->cmd[0]);
		}
		dick();
		free(line);
	}
	return (0);
}
