/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouliol <nbouliol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 16:44:03 by nbouliol          #+#    #+#             */
/*   Updated: 2014/11/27 12:06:26 by nbouliol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	char			*temp_dst;
	char			*temp_src;

	i = 0;
	temp_dst = (char *)dst;
	temp_src = (char *)src;
	if (dst && src)
	{
		while (i < n)
		{
			temp_dst[i] = temp_src[i];
			if (temp_dst[i] == c)
			{
				i++;
				return ((void *)dst + i);
			}
			i++;
		}
	}
	return (NULL);
}
