/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:42:42 by user00            #+#    #+#             */
/*   Updated: 2018/01/17 13:42:45 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pf_find_func(va_list *ap, t_pf *pf,
		char *f(va_list *, t_pf *), char **s)
{
	char	*str;
	int		i;

	i = 0;
	str = (*f)(ap, pf);
	if (str)
	{
		str = pf_find_mod(str, pf);
		while (str[i])
			(*s)[(pf->ans)++] = str[i++];
		ft_bzero(str, ft_strlen(str));
		ft_strdel(&str);
	}
	else
		pf_null_char(str, pf, s);
}

void	pf_null_char(char *str, t_pf *pf, char **s)
{
	int		i;

	i = 0;
	str = ft_strnew(1);
	if (pf->minus)
		(*s)[(pf->ans)++] = str[i];
	str = pf_find_mod(str, pf);
	if (ft_strlen(str))
		str[ft_strlen(str) - 1] = '\0';
	while (str[i])
		(*s)[(pf->ans)++] = str[i++];
	if (!pf->minus)
		(*s)[(pf->ans)++] = str[i];
}

void	pf_find_star(va_list *ap, t_pf *pf)
{
	int		i;
	char	*s;

	s = pf->format;
	while (*s)
	{
		if (s[0] == '.' && s[1] == '*')
		{
			i = pf_start_value(ap, pf);
			if (i > pf->size && pf->minus)
				i = pf->size;
			s += 2;
			if (pf->precision == -1 || pf->precision == 0)
				pf->precision = i;
		}
		if (s[0] == '*')
		{
			i = pf_start_value(ap, pf);
			if (pf->size == -1 || pf_alpha_after(s) == 1)
				pf->size = i;
		}
		s++;
	}
}

int		pf_start_value(va_list *ap, t_pf *pf)
{
	int		i;

	i = va_arg(*ap, int);
	if (i < 0)
	{
		i = -i;
		pf->minus = '-';
	}
	return (i);
}
