/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_manage_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:42:51 by user00            #+#    #+#             */
/*   Updated: 2018/01/17 13:42:54 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*pf_find_flag(char *s, t_pf *pf, int n)
{
	pf_flag_update(pf, n);
	if (pf->zero)
		s = pf_find_zero(s, pf, n);
	if (pf->hash && ft_strchr("poOxXfFeEaAgG", pf->conv))
		s = pf_find_hash(s, pf);
	if (pf->plus && ft_strchr("Did", pf->conv))
		s = ft_append("+", s, 2);
	if (pf->space && ft_strchr("Did", pf->conv))
		s = ft_append(" ", s, 2);
	return (s);
}

void	pf_flag_update(t_pf *pf, int n)
{
	if (pf->space && (pf->plus || n == 1))
		pf->space = '\0';
	if (pf->zero && (pf->minus || (ft_strchr(pf->format, '.')
					&& ft_strchr("dDiuU", pf->conv))))
		pf->zero = '\0';
	if (pf->plus && n == 1)
		pf->plus = '\0';
}

char	*pf_find_apostro(char *str, t_pf *pf)
{
	int		i;
	char	*s;

	i = ft_strlen(str);
	pf->apostro = '\0';
	if (i < 3)
		s = str;
	else
		s = ft_strnew(0);
	while (i > 3)
	{
		s = ft_append(s, ft_strsub(str, 0, 3), 3);
		s = ft_append(s, ",", 1);
		str += 3;
		i -= 3;
		if (i <= 3)
			s = ft_append(s, ft_strsub(str, 0, ft_strlen(str)), 3);
	}
	return (pf_revstr(s));
}

char	*pf_find_hash(char *s, t_pf *pf)
{
	if ((ft_strcmp(s, "0") == 0 || *s == '\0') && pf->conv != 'p')
		return (s);
	if (ft_strchr("pxX", pf->conv))
		return (ft_append("0x", s, 2));
	if (ft_strchr("oO", pf->conv) && s[0] != '0')
		return (ft_append("0", s, 2));
	return (s);
}

char	*pf_find_zero(char *s, t_pf *pf, int neg)
{
	if (pf->hash && ft_strchr("pxX", pf->conv))
		pf->size -= 2;
	if (pf->hash && ft_strchr("oO", pf->conv))
		pf->size -= 1;
	if (pf->space)
		pf->size -= 1;
	if (pf->plus || neg == 1)
		pf->size -= 1;
	s = pf_find_size(s, pf, "0");
	return (s);
}
