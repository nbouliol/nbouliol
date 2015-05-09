/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouliol <nbouliol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 16:52:19 by nbouliol          #+#    #+#             */
/*   Updated: 2014/11/19 15:16:28 by nbouliol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	size_t		i;
	size_t		len;

	i = 0;
	if (s != NULL && f != NULL)
	{
		len = ft_strlen(s);
		while (i < len)
		{
			f(s);
			s++;
			i++;
		}
	}
}
