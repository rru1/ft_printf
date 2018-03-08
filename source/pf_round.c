/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:45:23 by user00            #+#    #+#             */
/*   Updated: 2018/01/17 13:45:26 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double		pf_round_up(long double t)
{
	long double		d;

	d = (uintmax_t)t;
	if (t <= d)
		return (d);
	return (d + 1);
}

long double		pf_round_down(long double t)
{
	long double		d;

	d = (uintmax_t)t;
	if (t >= d)
		return (d);
	return (d - 1);
}

long double		pf_round_fraction(long double t)
{
	long double		up;
	long double		down;

	up = pf_round_up(t);
	down = pf_round_down(t);
	if (t - down == 0.5 && !((uintmax_t)down ^ 1))
		return (down);
	else if (up - t == 0.5)
		return (up);
	if (t - down >= 0.5)
		return (up);
	else
		return (down);
}

char			*pf_get_rounded_str(long double x, char *s)
{
	x = pf_round_fraction(x);
	if (x >= 10)
		s = ft_append(pf_round_dec_string(s, ft_strlen(s) - 1), "0", 0);
	else
		s = ft_append(s, ft_utoa((intmax_t)x, 10), 3);
	return (s);
}

char			*pf_round_dec_string(char *s, int len)
{
	if (s[len] != '.' && len >= 0)
	{
		s[len]++;
		if (s[len] > 57)
		{
			s[len] = 48;
			s = pf_round_dec_string(s, len - 1);
		}
	}
	if (len < 0)
		s = ft_append("1", s, 0);
	return (s);
}
