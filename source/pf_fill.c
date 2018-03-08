/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:42:34 by user00            #+#    #+#             */
/*   Updated: 2018/01/17 13:42:36 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pf_fill(t_pf *pf)
{
	char	*s;

	s = pf->format;
	while (*s)
	{
		if ((ft_isdigit(s[0]) == 1) && (s[0] != '0'))
			s = pf_update_int(pf, s, 0);
		if (s[0] == '.')
			s = pf_update_int(pf, s, 1);
		if (ft_strchr(LENGTH, s[0]))
			s = pf_update_len(s, pf);
		if (ft_strchr(CONV, s[0]))
			pf->conv = *s;
		if (ft_strchr(FLAGS, s[0]))
			s = pf_update_flag(s, pf);
		s++;
	}
}

char	*pf_update_int(t_pf *pf, char *s, int i)
{
	if (i == 0)
		pf->size = ft_atoi(s);
	if (i == 1)
	{
		pf->precision = pf_update_precision(s);
		while (s[0] == '.')
			s++;
	}
	while (ft_isdigit(s[0]) == 1)
		s++;
	return (s);
}

char	*pf_update_flag(char *s, t_pf *pf)
{
	if (*s == '#')
		pf->hash = '#';
	if (*s == ' ')
		pf->space = '!';
	if (*s == '-')
		pf->minus = '-';
	if (*s == '+')
		pf->plus = '+';
	if (*s == '\'')
		pf->apostro = '\'';
	if (*s == '*')
		pf->star = '*';
	if (*s == '0')
		pf->zero = '0';
	if (*s == '$')
		pf->dollar = '$';
	return (s);
}

char	*pf_update_len(char *s, t_pf *pf)
{
	if ((ft_strchr(LENGTH, s[1])) && ((ft_strchr(CONV, s[2]) ||
					(ft_strchr(FLAGS, s[2])))))
	{
		if (s[0] == s[1])
			pf->length = ft_toupper(s[0]);
		else
			pf->length = s[0];
		return (s + 2);
	}
	if ((ft_strchr(LENGTH, s[0])) && (ft_strchr(CONV, s[1])))
	{
		if (s[0] == 'L')
			pf->length = 'Z';
		else
			pf->length = s[0];
	}
	return (s + 1);
}

int		pf_update_precision(char *s)
{
	while (ft_strchr(s, '.'))
	{
		s = ft_strchr(s, '.');
		s++;
	}
	if (ft_isdigit(s[0]) == 1)
		return (ft_atoi(s));
	else
		return (0);
}
