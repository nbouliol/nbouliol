/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 17:38:09 by nbouliol          #+#    #+#             */
/*   Updated: 2015/05/07 16:57:44 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define Y 800
# define X 800

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	double		zoom;
	double		mov_x;
	double		mov_y;
	char		*str;
	int			bpp;
	int			endian;
	int			sline;
	int			julia;
	double		ju_cr;
	double		ju_ci;
	int			av;
	int			event;
	int			iter;
	int			m_on;
	int			col;
}				t_env;

int				expose_hook(t_env *e);
int				key_hook(int key, t_env *e);
int				motion_hook(int x, int y, t_env *e);
int				mouse_hook(int bouton, int x, int y, t_env *e);

int				init_img(t_env *e);
void			ft_put_pix_img(t_env *e, int x, int y, int color);
int				ft_rgb(int r, int g, int b);
int				get_color(int i, int iter);

void			raz(t_env *e);
void			julia_switcher(t_env *e);
void			julia(t_env *e);

void			mandelbrot(t_env *e);

void			tricorn(t_env *e);

void			vicky(t_env *e);

void			four(t_env *e);

#endif
