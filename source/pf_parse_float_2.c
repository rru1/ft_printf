/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_float_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:44:04 by user00            #+#    #+#             */
/*   Updated: 2018/01/17 13:44:07 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*pf_get_whole_part(long double x, char *s, t_pf *pf)
{
	int		i;

	i = 0;
	while (x > 10)
	{
		x /= 10;
		i--;
	}
	while (i <= 0)
	{
		s = ft_append(s, ft_utoa((intmax_t)x, 10), 3);
		x = (x - (intmax_t)x) * 10;
		i++;
	}
	if ((int)(x / 10) < (int)pf_round_fraction(x / 10) && pf->precision == 0)
		return (pf_round_dec_string(s, ft_strlen(s) - 1));
	if (pf_round_fraction(x) >= 9 && pf_check_nine(x, pf->precision))
		return (pf_round_dec_string(s, ft_strlen(s) - 1));
	return (s);
}

long double		pf_normalize_float(long double x1, int exp)
{
	if (exp < 0)
		while (exp++ < 0)
			x1 *= 10;
	else if (exp > 0)
		while (exp-- > 0)
		{
			x1 /= 10;
		}
	return (x1);
}

int				pf_check_normalize(long double x, int p)
{
	if ((intmax_t)x < 9)
		return (0);
	x = (x - (intmax_t)x) * 10;
	p--;
	while ((intmax_t)x == 9)
	{
		x = (x - (intmax_t)x) * 10;
		p--;
	}
	if ((intmax_t)x < 8)
		p++;
	if (p <= -1)
		return (1);
	else
		return (0);
}

int				pf_check_nine(long double x, int prec)
{
	while (prec >= 0 && (intmax_t)x >= 9)
	{
		x = (x - (intmax_t)x) * 10;
		prec--;
	}
	if (prec <= 0)
		return (1);
	return (0);
}
