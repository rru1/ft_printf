/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovolcov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:22:48 by ovolcov           #+#    #+#             */
/*   Updated: 2017/11/25 11:00:01 by ovolcov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		atoi_check(int num, char neg, int x)
{
	if (neg)
		num = -num;
	if (neg && x > 10)
		num = 0;
	if (!neg && x > 10)
		num = -1;
	return (num);
}

int				ft_atoi(const char *str)
{
	int		nbr;
	char	neg;
	int		i;

	i = 0;
	while (ft_iswhitespace(*str))
		str++;
	neg = (*str == '-');
	if (*str == '-' || *str == '+')
		str++;
	while (*str == '0')
		str++;
	nbr = 0;
	while (ft_isdigit(*str))
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
		i++;
	}
	nbr = atoi_check(nbr, neg, i);
	return (nbr);
}
