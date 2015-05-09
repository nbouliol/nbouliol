/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouliol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 18:57:30 by nbouliol          #+#    #+#             */
/*   Updated: 2015/05/05 18:57:31 by nbouliol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			calc(t_env *e, int i, int x, int y)
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
		tmp = (z_r * z_r * z_r * z_r * z_r) - 10 * z_r * z_r * z_r * z_i *
			z_i + 5 * z_r * z_i * z_i * z_i * z_i + c_r;
		z_i = 5 * z_r * z_r * z_r * z_r * z_i - 10 * z_r * z_r * z_i * z_i *
			z_i + z_i * z_i * z_i * z_i * z_i + c_i;
		z_r = tmp;
		i++;
	}
	return (i);
}

void		four(t_env *e)
{
	int			x;
	int			y;
	int			i;

	x = 0;
	while (x < X)
	{
		y = 0;
		while (y < Y)
		{
			i = calc(e, i, x, y);
			if (i == e->iter)
				ft_put_pix_img(e, x, y, 0xCCFFFF * i);
			else
				ft_put_pix_img(e, x, y, get_color(i, e->iter));
			y++;
		}
		x++;
	}
}
