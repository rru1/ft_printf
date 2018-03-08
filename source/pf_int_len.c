/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_int_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:43:00 by user00            #+#    #+#             */
/*   Updated: 2018/01/17 13:43:02 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*pf_int_length(intmax_t im, int base, t_pf *pf)
{
	char	*s;

	if (!(pf->length))
		s = ft_isneg((int)im, base);
	else if (pf->length == 'l')
		s = ft_isneg((long)im, base);
	else if (pf->length == 'L')
		s = ft_isneg((long long)im, base);
	else if (pf->length == 'j')
		s = ft_isneg((intmax_t)im, base);
	else if (pf->length == 'z')
		s = ft_isneg((ssize_t)im, base);
	else if (pf->length == 'h')
		s = ft_isneg((short)im, base);
	else if (pf->length == 'H')
		s = ft_isneg((char)im, base);
	return (s);
}

char	*pf_uint_length(uintmax_t im, int base, t_pf *pf)
{
	char	*s;

	if (!(pf->length))
		s = ft_utoa((unsigned int)im, base);
	else if (pf->length == 'l')
		s = ft_utoa((unsigned long)im, base);
	else if (pf->length == 'L')
		s = ft_utoa((unsigned long long)im, base);
	else if (pf->length == 'j')
		s = ft_utoa((uintmax_t)im, base);
	else if (pf->length == 'z')
		s = ft_utoa((ssize_t)im, base);
	else if (pf->length == 'h')
		s = ft_utoa((unsigned short)im, base);
	else if (pf->length == 'H')
		s = ft_utoa((unsigned char)im, base);
	return (s);
}

void	pf_free(t_pf *pf)
{
	ft_strdel(&(pf->format));
	ft_memdel((void **)&pf);
}
