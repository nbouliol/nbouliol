/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouliol <nbouliol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:42:17 by nbouliol          #+#    #+#             */
/*   Updated: 2014/11/06 15:53:56 by nbouliol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{
	int		digit;
	int		alpha;

	digit = ft_isdigit(c);
	alpha = ft_isalpha(c);
	if (digit == 1)
		return (1);
	else if (alpha == 1)
		return (1);
	return (0);
}
