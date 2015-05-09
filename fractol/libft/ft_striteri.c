/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouliol <nbouliol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 11:12:27 by nbouliol          #+#    #+#             */
/*   Updated: 2014/11/19 12:45:59 by nbouliol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	size_t			len;
	size_t			j;

	i = 0;
	j = 0;
	if (s && f)
	{
		len = ft_strlen(s);
		while (j < len)
		{
			f(i, s);
			i++;
			j++;
			s++;
		}
	}
}
