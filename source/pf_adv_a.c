/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_adv_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:41:19 by user00            #+#    #+#             */
/*   Updated: 2018/01/17 13:41:22 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			pf_iter_hex_dec(char *s)
{
	s[0]++;
	if (s[0] == 58)
		s[0] += 39;
}

char			*pf_round_hex_dec(char *s, int i, int j)
{
	if (j == i)
		return (s);
	while (j > i)
		if (s[j--] >= 56)
			pf_iter_hex_dec(s + j);
	if (s[i] > 56)
		pf_iter_hex_dec(s + i - 1);
	s[i] = '\0';
	i--;
	while (s[i] > 102 || s[i] == '.')
	{
		if (s[i] == '.')
			i--;
		else if (s[i] > 102)
		{
			s[i] = 48;
			if (s[i - 1] == '.')
				i--;
			pf_iter_hex_dec(s + i - 1);
		}
		i--;
	}
	return (s);
}

char			*pf_get_fract_part_a(long double x, char *s, t_pf *pf)
{
	int		i;

	i = ft_strlen(s);
	while (x > 0)
	{
		x = (x - (intmax_t)x) * 16;
		if (x != 0)
			s = ft_append(s, ft_utoa((intmax_t)x, 16), 3);
	}
	if (pf->precision == -1)
		pf->precision = ft_strlen(s) - i;
	else if (pf->precision > ((int)ft_strlen(s) - i))
		while (pf->precision > ((int)ft_strlen(s) - i))
			s = ft_append(s, "0", 1);
	else if (pf->precision < (int)ft_strlen(s))
		s = pf_round_hex_dec(s, pf->precision + i, ft_strlen(s));
	return (s);
}

long double		pf_get_exp_for_a(long double x, int *exp, int base)
{
	while (x >= base)
	{
		x /= 2;
		(*exp)++;
	}
	while ((x * 2) > 0 && (x * 2) < base)
	{
		x *= 2;
		(*exp)--;
	}
	return (x);
}

char			*pf_adv_a(long double d, t_pf *pf, char *s)
{
	int				exp;
	int				base;
	long double		x;

	exp = 0;
	if (pf->length == 'Z')
		base = 16;
	else
		base = 2;
	s = ft_append(s, "0x", 1);
	x = pf_get_exp_for_a(d, &exp, base);
	s = ft_append(s, ft_utoa((intmax_t)x, 16), 3);
	if (pf->precision != 0 && (x - (intmax_t)x) != 0.0)
		s = ft_append(s, ".", 1);
	s = pf_get_fract_part_a(x, s, pf);
	s = ft_append(s, "p", 1);
	if (exp < 0)
		s = ft_append(s, ft_isneg(exp, 10), 1);
	else if (exp >= 0)
	{
		s = ft_append(s, "+", 1);
		s = ft_append(s, ft_utoa(exp, 10), 3);
	}
	return (s);
}
