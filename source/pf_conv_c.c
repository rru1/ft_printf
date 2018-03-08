/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:41:35 by user00            #+#    #+#             */
/*   Updated: 2018/01/17 13:41:37 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*pf_conv_c(va_list *ap, t_pf *pf)
{
	char	*s;
	int		i;

	s = ft_strnew(1);
	i = ft_strlen(pf->format);
	if (ft_strcmp(s, pf->format) == 0)
		return (s);
	if (pf->length == 'l')
	{
		pf->conv = 'C';
		return (pf_conv_wc(ap, pf));
	}
	if (ft_strchr("c", (pf->format[i - 1])) != 0)
	{
		*s = (char)va_arg(*ap, int);
		if (*s == 0 || !(*s))
			return (NULL);
	}
	else
		*s = pf->format[i - 1];
	return (s);
}

char	*pf_conv_wc(va_list *ap, t_pf *pf)
{
	wchar_t		w;
	char		*s;

	if (pf->conv == 'C')
	{
		s = ft_strnew(1);
		s[0] = (char)va_arg(*ap, int);
		return (s);
	}
	w = va_arg(*ap, wchar_t);
	if (w == 0)
		return (NULL);
	s = pf_conv_wchar(w);
	return (s);
}

char	*pf_conv_wchar(wchar_t w)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)ft_strnew(4);
	if (w < 128)
		ptr[0] = w;
	else if (w < 2048)
	{
		ptr[0] = ((w & 1984) >> 6 | 192);
		ptr[1] = ((w & 63) | 128);
	}
	else if (w < 65536)
	{
		ptr[0] = ((w >> 12) | 224);
		ptr[1] = ((w & 4032) >> 6 | 128);
		ptr[2] = ((w & 63) | 128);
	}
	else if (w < 2097152)
	{
		ptr[0] = ((w >> 18) | 240);
		ptr[1] = ((w & 258048) >> 12 | 128);
		ptr[2] = ((w & 4032) >> 6 | 128);
		ptr[3] = ((w & 63) | 128);
	}
	return ((char *)ptr);
}
