/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:42:24 by user00            #+#    #+#             */
/*   Updated: 2018/01/17 13:42:27 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*pf_conv_s(va_list *ap, t_pf *pf)
{
	char	*s;

	s = NULL;
	if (pf->length == 'l')
		return (pf_conv_ws(ap, pf));
	s = va_arg(*ap, char *);
	if (s == NULL)
		s = "(null)";
	return (ft_strdup(s));
}

char	*pf_conv_ws(va_list *ap, t_pf *pf)
{
	wchar_t		*w;
	char		*r;
	int			i;
	int			j;

	i = 0;
	r = ft_strnew(0);
	w = va_arg(*ap, wchar_t *);
	if (w == NULL)
		return (ft_strdup("(null)"));
	while (w[i])
	{
		r = ft_append(r, pf_conv_wchar(w[i]), 3);
		if (((int)ft_strlen(r) > pf->precision) && (pf->precision > 2))
		{
			pf->precision -= (pf->precision - j);
			return (r);
		}
		j = ft_strlen(r);
		i++;
	}
	return (r);
}
