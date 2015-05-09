/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouliol <nbouliol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 13:01:43 by nbouliol          #+#    #+#             */
/*   Updated: 2014/11/15 17:14:38 by nbouliol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	nb;
	int	neg;

	nb = 0;
	neg = 0;
	while (*str == ' ' || *str == '\n' || *str == '\v' || *str == '\t'
			|| *str == '\r' || *str == '\f')
		str++;
	if (*str == '-')
	{
		neg = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str == '0')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + *str - '0';
		str++;
	}
	if (neg == 1)
		nb = -nb;
	return (nb);
}
