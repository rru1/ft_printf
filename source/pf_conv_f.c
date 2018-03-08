/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:41:49 by user00            #+#    #+#             */
/*   Updated: 2018/01/17 13:41:52 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*pf_conv_f(va_list *ap, t_pf *pf)
{
	long double		f;
	char			*s;

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

char	*pf_conv_bf(va_list *ap, t_pf *pf)
{
	return (pf_conv_f(ap, pf));
}
