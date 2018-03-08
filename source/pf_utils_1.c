/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:45:34 by user00            #+#    #+#             */
/*   Updated: 2018/01/17 13:45:37 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		pf_strfstr(char *b, char *l)
{
	if (b && l)
	{
		while (*b == *l)
		{
			b++;
			l++;
			if (*l == '\0')
				return (1);
		}
	}
	return (0);
}

void	pf_free_arr2(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		ft_memdel((void **)&(arr[i]));
		i++;
	}
	ft_memdel((void **)arr);
}

char	*pf_revstr(char *str)
{
	char	*s;
	int		i;
	int		j;

	s = ft_strdup(str);
	j = 0;
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		str[j++] = s[i--];
	}
	ft_strdel(&s);
	return (str);
}

int		pf_alpha_after(char *s)
{
	while (*s)
	{
		if (ft_isdigit(s[0]) == 1)
			return (0);
		else if (s[0] == '.')
		{
			s++;
			while (ft_isdigit(s[0]) && *s)
				s++;
		}
		s++;
	}
	return (1);
}

char	*pf_doubletoa(long double d, char *s, t_pf *pf)
{
	long double		x;
	int				i;

	i = 0;
	s = pf_get_whole_part(d, s, pf);
	if (pf->precision == 0)
		return (s);
	if (pf->precision != 0 || pf->hash == '#')
		s = ft_append(s, ".", 1);
	x = (d - (intmax_t)d) * 10;
	while (x != 0 || i < pf->precision)
	{
		if (i + 1 == pf->precision)
			return (pf_get_rounded_str(x, s));
		s = ft_append(s, ft_utoa((intmax_t)x, 10), 3);
		x = x - (intmax_t)x;
		x *= 10;
		i++;
	}
	return (s);
}
