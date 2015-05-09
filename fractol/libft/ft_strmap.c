/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouliol <nbouliol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 11:26:47 by nbouliol          #+#    #+#             */
/*   Updated: 2015/01/07 13:27:23 by nbouliol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_str;
	size_t	len;
	int		i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	new_str = (char *)malloc(sizeof(char) * len);
	if (!new_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = (*f)(s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
