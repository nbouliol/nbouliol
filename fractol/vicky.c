/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vicky.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 19:16:53 by nbouliol          #+#    #+#             */
/*   Updated: 2015/05/07 16:57:45 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		calcul(t_env *e, int i, int x, int y)
{
	double c_r;
	double c_i;
	double z_r;
	double z_i;
	double tmp;

	c_r = 2 * (x - X / 2) / (0.5 + e->zoom * X) + e->mov_x;
	c_i = (y - Y / 2) / (0.5 * e->zoom * Y) + e->mov_y;
	z_r = 0;
	z_i = 0;
	i = 0;
	while ((z_r * z_r + z_i * z_i) < 4 && i < e->iter)
	{
		tmp = fabs(z_r * z_r - z_i * z_i) - c_r;
		z_i = 2 * z_r * z_i - c_i;
		z_r = tmp;
		i++;
	}
	return (i);
}

void	vicky(t_env *e)
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
			i = calcul(e, i, x, y);
			if (i == e->iter)
				ft_put_pix_img(e, x, y, 0xFF9933);
			else
				ft_put_pix_img(e, x, y,
				ft_rgb(51, i * 204 / e->iter, i * 102 / e->iter));
			y++;
		}
		x++;
	}
}
