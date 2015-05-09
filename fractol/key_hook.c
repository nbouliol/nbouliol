/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 17:24:43 by nbouliol          #+#    #+#             */
/*   Updated: 2015/05/07 16:57:37 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ju_hook(int key, t_env *e)
{
	if (key == 2 && e->julia < 3)
	{
		e->julia++;
		raz(e);
	}
	else if (key == 0 && e->julia > 0)
	{
		e->julia--;
		raz(e);
	}
	else if (key == 7)
		e->m_on = 0;
	else if (key == 8)
		e->m_on = 1;
	else if (key == 11 && e->col == 0)
		e->col = 1;
	else if (key == 11 && e->col == 1)
		e->col = 0;
}

void	moves(int key, t_env *e)
{
	if (key == 123)
		e->mov_x += 0.1;
	else if (key == 124)
		e->mov_x -= 0.1;
	else if (key == 126)
		e->mov_y += 0.1;
	else if (key == 125)
		e->mov_y -= 0.1;
	else if (key == 69)
		e->zoom += 0.1;
	else if (key == 78 && e->zoom > 0.2)
		e->zoom -= 0.1;
}

int		key_hook(int key, t_env *e)
{
	if (key == 53)
		exit (0);
	else if (key == 1 && e->av == 5)
	{
		e->av = 1;
		raz(e);
	}
	else if (key == 1 && e->av != 6)
	{
		e->av++;
		raz(e);
	}
	moves(key, e);
	if (e->av == 2)
		ju_hook(key, e);
	expose_hook(e);
	return (0);
}
