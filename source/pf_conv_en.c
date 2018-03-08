/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_en.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:41:44 by user00            #+#    #+#             */
/*   Updated: 2018/01/17 13:41:45 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*pf_conv_n(va_list *ap, t_pf *pf)
{
	int		*f;

	f = va_arg(*ap, int *);
	if (pf->length == 'H')
		*(char *)f = (char)pf->ans;
	else if (pf->length == 'h')
		*(short *)f = (short)pf->ans;
	else if (pf->length == 'l' || pf->length == 'z')
		*(long *)f = (long)pf->ans;
	else if (pf->length == 'L')
		*(long long *)f = (long long)pf->ans;
	else if (pf->length == 'j')
		*(intmax_t *)f = (intmax_t)pf->ans;
	else
		*(int *)f = (int)pf->ans;
	return (ft_strdup(""));
}

char	*pf_conv_be(va_list *ap, t_pf *pf)
{
	return (pf_conv_e(ap, pf));
}

char	*pf_conv_e(va_list *ap, t_pf *pf)
{
	long double	f;
	char		*s;

	if (pf->length == 'Z')
		f = va_arg(*ap, long double);
	else
		f = va_arg(*ap, double);
	s = pf_check_inf(f);
	if (s)
		return (s);
	if (pf->precision == -1)
		pf->precision = 6;
	s = pf_parse_floats(f, pf);
	return (s);
}
