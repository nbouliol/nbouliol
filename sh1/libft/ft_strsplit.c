/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouliol <nbouliol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 12:20:57 by nbouliol          #+#    #+#             */
/*   Updated: 2015/03/26 15:13:42 by nbouliol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		words(const char *s, char c)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (j);
}

char	**ft_split(char **split, char *s, char c, size_t n)
{
	size_t	start;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	start = 0;
	while (s[i] && j < n)
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			split[j] = ft_strsub(s, start, i - start);
			j++;
		}
		else
			i++;
	}
	split[j] = 0;
	return (split);
}

char	**ft_strsplit(const char *s, char c)
{
	char	**tab;
	size_t	i;

	if (!s)
		return (NULL);
	i = words((char*)s, c);
	tab = (char**)malloc(sizeof(char*) * (i + 1));
	if (!tab)
		return (NULL);
	tab = ft_split(tab, (char*)s, c, i);
	return (tab);
}
