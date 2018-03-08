/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_float_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:43:54 by user00            #+#    #+#             */
/*   Updated: 2018/01/17 13:43:58 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*pf_check_inf(long double f)
{
	if (!(f == f))
		return (ft_strdup("nan"));
	if (f == -1.0 / 0.0)
		return (ft_strdup("-inf"));
	if (f == 1.0 / 0.0)
		return (ft_strdup("inf"));
	return (NULL);
}

char	*pf_get_exp(long double d, char *s, t_pf *pf, int exp)
{
	long double x;

	x = pf_normalize_float(d, exp);
	if (pf_check_normalize(x, pf->precision) || (intmax_t)x == 10)
	{
		x /= 10;
		exp++;
	}
	s = pf_doubletoa(x, s, pf);
	if (pf->conv == 'g' || pf->conv == 'G')
		s = pf_cut_zero(s, ft_strlen(s) - 1, pf);
	s = ft_append(s, "e", 1);
	if (exp < 0)
	{
		s = ft_append(s, "-", 1);
		exp = -exp;
	}
	else
		s = ft_append(s, "+", 1);
	if (exp < 10)
		s = ft_append(s, "0", 1);
	s = ft_append(s, ft_utoa(exp, 10), 2);
	return (s);
}

int		pf_find_exp(long double d)
{
	int		exp;

	exp = 0;
	while (d < 1 && d > 0)
	{
		d *= 10;
		exp--;
	}
	while (d > 10)
	{
		d /= 10;
		exp++;
	}
	return (exp);
}

char	*pf_conv_adv_g(long double d, t_pf *pf, char *s, int exp)
{
	if (exp < -4 || exp >= pf->precision)
	{
		pf->precision--;
		s = pf_get_exp(d, s, pf, exp);
	}
	else
	{
		pf->precision = pf->precision - exp - 1;
		s = pf_doubletoa(d, s, pf);
	}
	return (s);
}

char	*pf_parse_floats(long double d, t_pf *pf)
{
	char	*s;
	int		exp;
	int		n;

	s = ft_strnew(1);
	n = 0;
	if (d < 0.0)
	{
		n = 1;
		d = -d;
	}
	exp = pf_find_exp(d);
	if (pf->conv == 'f' || pf->conv == 'F')
		s = pf_doubletoa(d, s, pf);
	else if (pf->conv == 'e' || pf->conv == 'E')
		s = pf_get_exp(d, s, pf, exp);
	else if (pf->conv == 'g' || pf->conv == 'G')
		s = pf_conv_adv_g(d, pf, s, exp);
	if (n == 1)
		s = ft_append("-", s, 2);
	return (s);
}
