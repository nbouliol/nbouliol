/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouliol <nbouliol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 12:32:03 by nbouliol          #+#    #+#             */
/*   Updated: 2015/01/07 10:59:36 by nbouliol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ntol(int n)
{
	char	*str;
	char	*tmp;
	int		i;
	int		j;

	str = ft_memalloc(11);
	tmp = ft_memalloc(11);
	i = 0;
	j = 0;
	if (n < 0)
	{
		str[i++] = '-';
		n = -n;
	}
	while (n)
	{
		tmp[j++] = (n % 10) + '0';
		n = n / 10;
	}
	j--;
	while (j >= 0)
		str[i++] = tmp[j--];
	str[i] = 0;
	return (str);
}

char	*ft_itoa(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	else if (!n)
		return (NULL);
	else if (n == -2147483648)
		return ("-2147483648");
	else
		return (ntol(n));
}
