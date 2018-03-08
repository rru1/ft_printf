/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:41:27 by user00            #+#    #+#             */
/*   Updated: 2018/01/17 13:41:31 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*pf_conv_a(va_list *ap, t_pf *pf)
{
	char			*s;
	long double		f;

	if (pf->length == 'Z')
		f = va_arg(*ap, long double);
	else
		f = va_arg(*ap, double);
	s = pf_check_inf(f);
	if (s)
		return (s);
	s = ft_strnew(1);
	if (f < 0)
	{
		s[0] = '-';
		f = -f;
	}
	s = pf_adv_a(f, pf, s);
	return (s);
}

char	*pf_conv_ba(va_list *ap, t_pf *pf)
{
	return (pf_conv_a(ap, pf));
}
