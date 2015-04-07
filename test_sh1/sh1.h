/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouliol <nbouliol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 14:51:51 by nbouliol          #+#    #+#             */
/*   Updated: 2015/03/24 17:23:10 by nbouliol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH1_H
# define SH1_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <dirent.h>
# include <signal.h>
# include <stdio.h>
# include <sys/param.h>

typedef struct		s_fat
{
	char			**env;
	char			**cmd;
	char			**path;
	char			*pwd;
	char			*oldpwd;
}					t_fat;

void				dick();
int					ft_lect(t_fat *k, char **env);
int					ft_check2(t_fat *k);

void				ft_putenv(char **env);
void				cd(t_fat *k);
char				*get_home(char **env);

void				get_old_pwd(t_fat *k);
void				get_pwd(t_fat *k);

char				*ft_check(t_fat *k);

void				ft_unsetenv(t_fat *k, char *str);
char				**ft_setenv(char **env, char *str);
void				ft_str_swap(char *a, char *b);
char				*prompt(t_fat *k);
void				ft_path_env(char **env, t_fat *k);
int					ft_search(char **env, char *keyword);
char				**env_cpy(char **env);
char				**malloc_char(char **tab, int x, int y);

int					env_cnt(char **env);
void				delete_line(t_fat *k, char *key);
void				resize_tab(t_fat *k);

void				error(char *str);
char				*ft_epur_str(char *src);
void				error(char *str);
void				dick();
void				handle_signal(int signo);

#endif
