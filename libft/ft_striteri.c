/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovolcov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:23:02 by ovolcov           #+#    #+#             */
/*   Updated: 2017/11/20 16:23:06 by ovolcov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s != NULL && f != NULL)
	{
		j = ft_strlen(s);
		while (i < j)
		{
			(*f)(i, s);
			s++;
			i++;
		}
	}
}
