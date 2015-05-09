/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 19:24:49 by nbouliol          #+#    #+#             */
/*   Updated: 2015/05/07 16:57:43 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		check(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr("wrong number of arguments\n");
		return (-1);
	}
	if (ft_strcmp(av[1], "julia") != 0 && ft_strcmp(av[1], "mandelbrot") != 0
		&& ft_strcmp(av[1], "tricorn") != 0 && ft_strcmp(av[1], "medusa") != 0
		&& ft_strcmp(av[1], "four") != 0)
	{
		ft_putendl("mandelbrot");
		ft_putendl("julia");
		ft_putendl("tricorn");
		ft_putendl("medusa");
		ft_putendl("four");
		return (-1);
	}
	return (0);
}

void	check_2(char **av, t_env *e)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		e->av = 1;
	if (ft_strcmp(av[1], "julia") == 0)
	{
		e->event = 0;
		e->julia = 0;
		e->av = 2;
		e->m_on = 0;
		e->col = 0;
	}
	if (ft_strcmp(av[1], "tricorn") == 0)
		e->av = 3;
	if (ft_strcmp(av[1], "medusa") == 0)
		e->av = 4;
	if (ft_strcmp(av[1], "four") == 0)
		e->av = 5;
}

int		main(int ac, char **av)
{
	t_env *e;

	if (check(ac, av) == -1)
		return (-1);
	e = (t_env *)malloc(sizeof(t_env));
	check_2(av, e);
	raz(e);
	if ((e->mlx = mlx_init()) == NULL)
	{
		ft_putstr("MLX_INIT ERROR\n");
		return (-1);
	}
	e->win = mlx_new_window(e->mlx, X, Y, "fractol");
	init_img(e);
	mlx_mouse_hook (e->win, mouse_hook, e);
	mlx_hook(e->win, 2, 3, key_hook, e);
	mlx_hook(e->win, 6, 1L << 6, motion_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
