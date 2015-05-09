/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 18:36:20 by nbouliol          #+#    #+#             */
/*   Updated: 2015/05/07 16:57:42 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		wh_frac(t_env *e)
{
	if (e->av == 1)
		mandelbrot(e);
	else if (e->av == 2)
		julia(e);
	else if (e->av == 3)
		tricorn(e);
	else if (e->av == 4)
		vicky(e);
	else if (e->av == 5)
		four(e);
}

int			expose_hook(t_env *e)
{
	ft_bzero(e->str, Y * e->sline);
	wh_frac(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int			motion_hook(int x, int y, t_env *e)
{
	if (e->av == 2 && e->m_on == 1)
	{
		if (x > 0 && x < X && y > 0 && y < Y)
		{
			if (x > 500 / 2 && x > 0)
				e->ju_cr = ((double)(x - 250) / 100);
			else if (x < 500 / 2 && x > 0)
				e->ju_cr = ((double)(x - 250) / 100);
			else if (y > 500 / 2 && y > 0)
				e->ju_ci = ((double)(y - 250) / 100);
			else if (y < 500 / 2 && y > 0)
				e->ju_ci = ((double)(y - 250) / 100);
		}
		expose_hook(e);
		e->event = 1;
	}
	return (0);
}

void		tri_mouse(int bouton, int x, int y, t_env *e)
{
	if (bouton == 4 && e->zoom < 100)
	{
		e->zoom += 0.1;
		e->mov_y = y / 150;
		e->mov_x = x / 150;
	}
	else if (bouton == 5 && e->zoom > 0.2)
	{
		e->zoom -= 0.1;
		e->mov_y = y / 150;
		e->mov_x = x / 150;
	}
}

int			mouse_hook(int bouton, int x, int y, t_env *e)
{
	if (bouton == 1)
		e->iter *= 1.5;
	else if (bouton == 2 && e->iter > 34)
		e->iter /= 1.5;
	else if (bouton == 3)
		raz(e);
	else if (e->av == 1 || e->av == 2 || e->av == 4 || e->av == 5)
	{
		if (bouton == 4 && e->zoom < 100)
			e->zoom += 0.1;
		else if (bouton == 5 && e->zoom > 0.2)
			e->zoom -= 0.1;
	}
	else if (e->av == 3)
		tri_mouse(bouton, x, y, e);
	expose_hook(e);
	return (0);
}
