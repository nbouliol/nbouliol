/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 19:37:13 by nbouliol          #+#    #+#             */
/*   Updated: 2015/05/07 16:57:45 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mini_raz(t_env *e)
{
	if (e->av == 4)
	{
		e->mov_x = 1.5;
		e->mov_y = 0;
		e->zoom = 1.9;
		e->iter = 25;
	}
	else if (e->av == 5)
	{
		e->mov_x = 0;
		e->mov_y = 0;
		e->zoom = 1;
		e->iter = 40;
	}
}

void		raz(t_env *e)
{
	if (e->av == 1)
	{
		e->mov_x = -0.7;
		e->mov_y = 0;
		e->zoom = 0.7;
		e->iter = 50;
	}
	else if (e->av == 2)
	{
		e->mov_x = 0;
		e->mov_y = 0;
		e->zoom = 0.8;
		e->iter = 150;
		e->event = 0;
	}
	else if (e->av == 3)
	{
		e->mov_x = 0;
		e->mov_y = 0;
		e->zoom = 0.5;
		e->iter = 50;
	}
	mini_raz(e);
}

void		julia_switcher(t_env *e)
{
	if (e->julia == 0)
	{
		e->ju_cr = 0.285;
		e->ju_ci = 0.01;
	}
	else if (e->julia == 1)
	{
		e->ju_cr = -0.7927;
		e->ju_ci = 0.1609;
	}
	else if (e->julia == 2)
	{
		e->ju_cr = -0.3380;
		e->ju_ci = -0.6230;
	}
	else if (e->julia == 3)
	{
		e->ju_cr = -0.5403;
		e->ju_ci = 0.5403;
	}
}

int			calc_ul(t_env *e, int i, int x, int y)
{
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		tmp;

	c_r = e->ju_cr;
	c_i = e->ju_ci;
	z_r = 2 * (x - X / 2) / (0.5 + e->zoom * X) + e->mov_x;
	z_i = (y - Y / 2) / (0.5 * e->zoom * Y) + e->mov_y;
	i = 0;
	while ((z_r * z_r + z_i * z_i) < 4 && i < e->iter)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * z_i * tmp + c_i;
		i++;
	}
	return (i);
}

void		julia(t_env *e)
{
	int			i;
	int			x;
	int			y;

	x = 0;
	if (e->event == 0)
		julia_switcher(e);
	while (x < X)
	{
		y = 0;
		while (y < Y)
		{
			i = calc_ul(e, i, x, y);
			if (i == e->iter)
				ft_put_pix_img(e, x, y, 0xFF00FF);
			else if (i >= 0.25 * e->iter && i <= 0.75 * e->iter && e->col == 1)
				ft_put_pix_img(e, x, y, ft_rgb(0, 0, 42 * i));
			else
				ft_put_pix_img(e, x, y, ft_rgb(12, i * 255 /
					e->iter, i * 75 / e->iter));
			y++;
		}
		x++;
	}
}
