/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouliol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 12:24:04 by nbouliol          #+#    #+#             */
/*   Updated: 2015/01/07 12:10:54 by nbouliol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*cpy;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		cpy = (void*)malloc(sizeof(content) * content_size);
		if (cpy == NULL)
			return (NULL);
		cpy = ft_memcpy(cpy, content, content_size);
		new->content = cpy;
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
