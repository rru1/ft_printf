/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_modifiers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:43:08 by user00            #+#    #+#             */
/*   Updated: 2018/01/17 13:43:36 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*pf_find_mod(char *s, t_pf *pf)
{
	int		n;

	n = 0;
	if (s[0] == '-')
	{
		s = ft_strcpy(s, s + 1);
		n = 1;
	}
	s = pf_find_precision(s, pf);
	s = pf_find_flag(s, pf, n);
	if (pf->apostro && ft_strchr("diu", pf->conv))
		s = pf_find_apostro(pf_revstr(s), pf);
	if (n == 1)
		s = ft_append("-", s, 2);
	s = pf_find_size(s, pf, " ");
	if (ft_strchr("AEFGX", pf->conv))
		s = ft_capitalizer(s);
	return (s);
}

char	*pf_find_precision(char *s, t_pf *pf)
{
	if ((pf->precision == 0) && (ft_strcmp(s, "0") == 0) &&
		!(ft_strchr("fFgGaA", pf->conv)))
		return (ft_strnew(0));
	if (ft_strchr("sS", pf->conv))
		if (pf->precision != -1)
			s = ft_strsub(s, 0, pf->precision);
	if (ft_strchr("dDiuUoOxXp", pf->conv))
	{
		if (pf->precision == -1)
			pf->precision = 1;
		if (ft_strchr("dDiuUoOxXp", pf->conv) && (*s))
			while (pf->precision > (int)ft_strlen(s))
				s = ft_append("0", s, 2);
	}
	return (s);
}

char	*pf_find_size(char *s, t_pf *pf, char *ptr)
{
	int		i;

	i = ft_strlen(s);
	if (pf->size > 0)
		pf->size -= i;
	if (pf->minus)
		while (pf->size-- > 0)
			s = ft_append(s, ptr, 1);
	else
		while (pf->size-- > 0)
			s = ft_append(ptr, s, 2);
	return (s);
}
