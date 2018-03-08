/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovolcov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:26:19 by ovolcov           #+#    #+#             */
/*   Updated: 2017/11/20 16:26:22 by ovolcov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_strnew(size_t size)
{
	char	*set;

	if (!(set = (char *)malloc(size + 1)))
		return (NULL);
	ft_memset(set, '\0', size + 1);
	return (set);
}
