/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 19:21:39 by nbouliol          #+#    #+#             */
/*   Updated: 2015/05/07 16:57:46 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		calcoul(t_env *e, int i, int x, int y)
{
	double		cr;
	double		ci;
	double		tmp;
	double		zr;
	double		zi;

	cr = 2 * (x - X / 2) / (0.5 + e->zoom * X) + e->mov_x;
	ci = (y - Y / 2) / (0.5 * e->zoom * Y) + e->mov_y;
	i = 0;
	tmp = 0;
	zr = 0;
	zi = 0;
	while (zr * zr + zi * zi < 4 && i < e->iter)
	{
		tmp = zr;
		zr = zi * zi - zr * zr - cr;
		zi = 2 * zi * tmp - ci;
		i++;
	}
	return (i);
}

void	tricorn(t_env *e)
{
	double		x;
	double		y;
	int			i;

	x = 0;
	while (x < X)
	{
		while (y < X)
		{
			i = calcoul(e, i, x, y);
			if (i != e->iter)
				ft_put_pix_img(e, x, y, ft_rgb(
					240 * e->iter, 219 * i - e->iter, 17 + e->iter));
			else
				ft_put_pix_img(e, x, y, (i * 500 << 2));
			y++;
		}
		y = 0;
		x++;
	}
}
