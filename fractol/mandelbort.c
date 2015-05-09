/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 18:52:12 by nbouliol          #+#    #+#             */
/*   Updated: 2015/05/07 16:57:47 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		test(t_env *e, int i, int x, int y)
{
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		tmp;

	c_r = 2 * (x - X / 2) / (0.5 + e->zoom * X) + e->mov_x;
	c_i = (y - Y / 2) / (0.5 * e->zoom * Y) + e->mov_y;
	z_r = 0;
	z_i = 0;
	i = 0;
	while ((z_r * z_r + z_i * z_i) < 4 && i < e->iter)
	{
		tmp = z_r;
		z_r = (z_r * z_r) - (z_i * z_i) + c_r;
		z_i = 2 * z_i * tmp + c_i;
		i++;
	}
	return (i);
}

void	mandelbrot(t_env *e)
{
	int			x;
	int			y;
	int			i;

	i = 0;
	x = 0;
	while (x < X)
	{
		y = 0;
		while (y < Y)
		{
			i = test(e, i, x, y);
			if (i == e->iter)
				ft_put_pix_img(e, x, y, 0x3399FF);
			else if (i >= 0.25 * e->iter && i <= 0.75 * e->iter)
				ft_put_pix_img(e, x, y, ft_rgb(42, 42 * i, 42 / e->iter));
			else
				ft_put_pix_img(e, x, y,
				ft_rgb(12, i * 255 / e->iter, i * 75 / e->iter));
			y++;
		}
		x++;
	}
}
