/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouliol <nbouliol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:27:12 by nbouliol          #+#    #+#             */
/*   Updated: 2014/11/18 12:38:00 by nbouliol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		j;

	j = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)s + j);
	j--;
	while (s[j])
	{
		if (s[j] == (char)c)
			return ((char *)s + j);
		j--;
	}
	return (NULL);
}
