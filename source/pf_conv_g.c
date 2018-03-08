/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_g.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:41:58 by user00            #+#    #+#             */
/*   Updated: 2018/01/17 13:42:00 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*pf_cut_zero(char *s, int l, t_pf *pf)
{
	if (pf->precision == 0)
		return (s);
	while (s[l] == 48)
		s[l--] = '\0';
	if (s[l] == '.')
		s[l] = '\0';
	return (s);
}

char	*pf_conv_g(va_list *ap, t_pf *pf)
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
	if (pf->precision == 0)
		pf->precision = 1;
	s = pf_parse_floats(f, pf);
	s = pf_cut_zero(s, ft_strlen(s) - 1, pf);
	return (s);
}

char	*pf_conv_bg(va_list *ap, t_pf *pf)
{
	return (pf_conv_g(ap, pf));
}
