/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_epur_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouliol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 14:47:11 by nbouliol          #+#    #+#             */
/*   Updated: 2015/03/26 15:14:29 by nbouliol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			cnt(char *s)
{
	int		i;

	i = 0;
	while (s[i] == ' ' || s[i] == '	')
		i++;
	return (i);
}

void		tri(char *str, char *ret)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if ((str[i] == ' ' && !str[i - 1]) || (str[i] == '	' && !str[i - 1]))
			i = i + cnt(str);
		if ((str[i] == ' ' && str[i + 1] == ' ') ||
			(str[i] == ' ' && str[i + 1] == '	') ||
			(str[i] == ' ' && !str[i - 1]) ||
			(str[i] == '	' && str[i + 1] == '	') ||
			(str[i] == '	' && str[i + 1] == ' ') ||
			(str[i] == '	' && !str[i - 1]))
		{
			i++;
			continue ;
		}
		if ((str[i] == ' ' && str[i + 1] == '\0') ||
				(str[i] == '	' && str[i + 1] == '\0'))
			str[i] = '\0';
		ret[j++] = str[i++];
	}
	ret[j] = 0;
}

char		*epur_str(char *str)
{
	int		i;
	char	ret[ft_strlen(str)];
	int		j;

	if (!str)
		return (NULL);
	*ret = 0;
	tri(str, ret);
	i = 0;
	j = 0;
	while (ret[i])
		str[j++] = ret[i++];
	str[j] = 0;
	return (str);
}
