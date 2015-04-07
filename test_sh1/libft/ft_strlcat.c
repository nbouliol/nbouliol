/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouliol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:15:19 by nbouliol          #+#    #+#             */
/*   Updated: 2014/11/27 15:29:07 by nbouliol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ldst;
	size_t	lsrc;
	char	*tmp;

	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	tmp = dst;
	if (size < ldst + 1)
		return (lsrc + size);
	else
	{
		ft_memcpy(tmp + ldst, src, sizeof(char) * (size - ldst - 1));
		dst[size - 1] = '\0';
	}
	return (ldst + lsrc);
}
