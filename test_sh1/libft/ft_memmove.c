/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouliol <nbouliol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 11:18:31 by nbouliol          #+#    #+#             */
/*   Updated: 2014/11/27 16:12:10 by nbouliol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*temp;

	if (dst && src)
	{
		temp = (char *)malloc(sizeof(char) * len);
		ft_memcpy(temp, src, len);
		ft_memcpy(dst, temp, len);
	}
	return (dst);
}
