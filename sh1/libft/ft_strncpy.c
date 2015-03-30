/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouliol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:09:20 by nbouliol          #+#    #+#             */
/*   Updated: 2014/11/27 16:09:07 by nbouliol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t		i;

	if (dst && src)
	{
		i = 0;
		while (src[i] != '\0' && i < n)
		{
			dst[i] = src[i];
			i++;
		}
		if (i < n)
		{
			while (i != n)
			{
				dst[i] = '\0';
				i++;
			}
		}
		return (dst);
	}
	return (NULL);
}
