/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouliol <nbouliol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 12:17:08 by nbouliol          #+#    #+#             */
/*   Updated: 2015/01/07 12:20:08 by nbouliol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;

	if (s1 && s2)
	{
		tmp_s1 = (unsigned char *)s1;
		tmp_s2 = (unsigned char *)s2;
		i = 0;
		while (i != n)
		{
			if (tmp_s1[i] != tmp_s2[i])
				return (tmp_s1[i] - tmp_s2[i]);
			i++;
		}
	}
	return (0);
}
