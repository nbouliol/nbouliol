/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouliol <nbouliol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 15:44:24 by nbouliol          #+#    #+#             */
/*   Updated: 2014/11/18 16:55:23 by nbouliol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*str;
	int			len;
	int			i;
	int			j;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	j = 0;
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t' || s[len] == '\0')
		len--;
	while (i <= len)
	{
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}
