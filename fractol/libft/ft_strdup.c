/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouliol <nbouliol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 11:35:19 by nbouliol          #+#    #+#             */
/*   Updated: 2014/11/17 15:08:13 by nbouliol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*new_str;
	size_t		len;
	size_t		x;

	x = 0;
	len = ft_strlen(s1);
	new_str = (char*)malloc(sizeof(char) * (len + 1));
	while (s1[x] != '\0')
	{
		new_str[x] = s1[x];
		x++;
	}
	new_str[x] = '\0';
	return (new_str);
}
