/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouliol <nbouliol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 16:31:55 by nbouliol          #+#    #+#             */
/*   Updated: 2014/11/18 15:16:25 by nbouliol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*str;
	size_t		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	while (i <= size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
