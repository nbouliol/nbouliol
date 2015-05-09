/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouliol <nbouliol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 11:51:48 by nbouliol          #+#    #+#             */
/*   Updated: 2015/01/07 13:40:31 by nbouliol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*new_str;
	size_t		len;
	int			i;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	new_str = ft_strnew(len);
	while (s[i])
	{
		new_str[i] = (*f)(i, s[i]);
		i++;
	}
	return (new_str);
}
