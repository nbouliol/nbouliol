/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouliol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 16:49:13 by nbouliol          #+#    #+#             */
/*   Updated: 2015/05/05 16:49:14 by nbouliol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			init_img(t_env *e)
{
	if (!(e->img = mlx_new_image(e->mlx, X, Y)))
		return (-1);
	if (!(e->str = mlx_get_data_addr(e->img, &(e->bpp), &(e->sline)
		, &(e->endian))))
		return (-1);
	return (0);
}

void		ft_put_pix_img(t_env *e, int x, int y, int color)
{
	int			i;

	i = ((e->bpp / 8) * x) + ((e->sline) * y);
	if (i >= 0 && i < Y * e->sline && i > y * e->sline && i <
			(y * e->sline) + ((e->bpp / 8) * X))
	{
		e->str[i] = color;
		e->str[i + 1] = color >> 8;
		e->str[i + 2] = color >> 16;
	}
}

int			ft_rgb(int r, int g, int b)
{
	int			xolor;

	xolor = 0;
	xolor += ((r << 16) + (g << 8) + b);
	return (xolor);
}

int			get_color(int i, int iter)
{
	int			c;
	int			n;
	int			tab[3];
	double		t;

	t = (double)i / (double)iter;
	i = (int)(t * (double)(256 * 256 * 256));
	c = 256;
	tab[2] = i / (c * c);
	n = i - tab[2] * c * c;
	tab[0] = n / c;
	tab[1] = n - tab[0] * c;
	return ((tab[0] << 16) | (tab[1] << 8) | tab[2]);
}
