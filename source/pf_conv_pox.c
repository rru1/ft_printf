/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_pox.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:42:12 by user00            #+#    #+#             */
/*   Updated: 2018/01/17 13:42:15 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*pf_conv_o(va_list *ap, t_pf *pf)
{
	uintmax_t	um;
	char		*s;

	um = va_arg(*ap, uintmax_t);
	s = pf_uint_length(um, 8, pf);
	if ((um == 0) && (pf->hash == '#') && (pf->precision == 0))
		pf->precision++;
	return (s);
}

char	*pf_conv_lo(va_list *ap, t_pf *pf)
{
	uintmax_t	um;
	char		*s;

	um = va_arg(*ap, uintmax_t);
	pf->length = 'l';
	s = pf_uint_length(um, 8, pf);
	if ((um == 0) && (pf->hash == '#') && (pf->precision == 0))
		pf->precision++;
	return (s);
}

char	*pf_conv_x(va_list *ap, t_pf *pf)
{
	uintmax_t	um;
	char		*s;

	um = va_arg(*ap, uintmax_t);
	s = pf_uint_length(um, 16, pf);
	return (s);
}

char	*pf_conv_lx(va_list *ap, t_pf *pf)
{
	uintmax_t	um;
	char		*s;

	um = va_arg(*ap, uintmax_t);
	s = pf_uint_length(um, 16, pf);
	return (s);
}

char	*pf_conv_p(va_list *ap, t_pf *pf)
{
	void	*tmp;
	char	*s;

	tmp = va_arg(*ap, void *);
	s = ft_utoa((uintmax_t)tmp, 16);
	pf->hash = '#';
	return (s);
}
