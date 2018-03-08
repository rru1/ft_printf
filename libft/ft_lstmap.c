/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovolcov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:04:35 by ovolcov           #+#    #+#             */
/*   Updated: 2017/11/20 15:04:38 by ovolcov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list*))
{
	t_list	*res;
	t_list	*ptr;
	t_list	*data;

	if (!lst || !f)
		return (NULL);
	data = (*f)(lst);
	if ((res = ft_lstnew(data->content, data->content_size)))
	{
		ptr = res;
		lst = lst->next;
		while (lst)
		{
			data = (*f)(lst);
			if (!(ptr->next = ft_lstnew(data->content, data->content_size)))
				return (NULL);
			ptr = ptr->next;
			lst = lst->next;
		}
	}
	return (res);
}
