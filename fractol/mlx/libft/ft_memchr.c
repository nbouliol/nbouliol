/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouliol <nbouliol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 11:50:01 by nbouliol          #+#    #+#             */
/*   Updated: 2014/11/27 12:10:22 by nbouliol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*temp_s;
	size_t			i;

	i = 0;
	temp_s = (char *)s;
	if (s && n > 0)
	{
		while (i < n)
		{
			if ((unsigned char)temp_s[i] == (unsigned char)c)
				return ((void *)temp_s + i);
			i++;
		}
	}
	return (NULL);
}
