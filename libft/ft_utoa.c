/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:37:59 by user00            #+#    #+#             */
/*   Updated: 2018/01/17 13:38:09 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa(uintmax_t n, int base)
{
	char	*r;
	int		i;
	int		j;

	i = ft_nbrlen(n / base, base);
	r = (char *)malloc(i + 1);
	r[i] = '\0';
	i--;
	while (n >= base)
	{
		j = n % base;
		r[i] = HEX[j];
		n /= base;
		i--;
	}
	r[i] = HEX[n];
	return (r);
}
