/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouliol <nbouliol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:27:10 by nbouliol          #+#    #+#             */
/*   Updated: 2014/11/08 12:11:44 by nbouliol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*temp_dst;
	char		*temp_src;

	i = 0;
	temp_dst = (char *)dst;
	temp_src = (char *)src;
	while (i < n)
	{
		temp_dst[i] = temp_src[i];
		i++;
	}
	return ((void *)temp_dst);
}
