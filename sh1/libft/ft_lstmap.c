/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouliol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 15:47:41 by nbouliol          #+#    #+#             */
/*   Updated: 2015/01/07 13:40:07 by nbouliol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*ret;
	t_list		*tmp;
	t_list		*bgn;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	if (!tmp || !(ret = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	bgn = ret;
	while (lst->next)
	{
		tmp = f(lst->next);
		if (tmp && (ret->next = ft_lstnew(tmp->content, tmp->content_size)))
		{
			ret = ret->next;
			lst = lst->next;
		}
		else
			lst = ft_lstnew(NULL, 0);
	}
	return (bgn);
}
