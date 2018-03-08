/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovolcov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:05:50 by ovolcov           #+#    #+#             */
/*   Updated: 2017/11/20 15:05:51 by ovolcov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ptrd;
	unsigned char	*ptrs;
	int				i;

	i = 0;
	ptrd = (unsigned char *)dst;
	ptrs = (unsigned char *)src;
	while (n)
	{
		ptrd[i] = ptrs[i];
		if (ptrs[i] == (unsigned char)c)
			return (&((char *)ptrd)[i + 1]);
		i++;
		n--;
	}
	return (NULL);
}
