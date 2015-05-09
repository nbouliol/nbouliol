/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouliol <nbouliol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 15:43:52 by nbouliol          #+#    #+#             */
/*   Updated: 2014/11/17 15:47:34 by nbouliol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;
	char	*tmp_str;

	i = 0;
	tmp_str = (char *)str;
	while (i < n)
	{
		tmp_str[i] = c;
		i++;
	}
	return ((void *)tmp_str);
}
