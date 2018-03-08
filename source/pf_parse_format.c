/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:44:14 by user00            #+#    #+#             */
/*   Updated: 2018/01/17 13:45:15 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		pf_parse_format(char *format, va_list ap, char **s, void *func[])
{
	static t_pf		*pf;
	int				ans;
	int				i;

	i = 0;
	ans = 0;
	*s = ft_strnew(9000);
	while (*format)
	{
		if (*format != '%' && *format)
			format += pf_is_empty(format, s, &ans);
		else if (*format == '%' && format[1])
		{
			pf = pf_get_arg(pf, format, i++, ans);
			format += pf_parse_arg(pf, (va_list *)(ap), s, func);
			ans = pf->ans;
			pf_free(pf);
		}
		else if (*format == '%' && format[1] == '\0')
			format++;
	}
	return (ans);
}

t_pf	*pf_get_arg(t_pf *pf, char *format, int arg, int ans)
{
	pf = (t_pf *)malloc(sizeof(t_pf));
	*pf = (t_pf)PFS;
	pf->va_num = arg;
	pf->ans = ans;
	pf_get_format(format + 1, pf);
	return (pf);
}

char	*pf_get_format(char *format, t_pf *pf)
{
	int		i;

	i = 0;
	while (format[i] != '%' && format[i])
	{
		if (ft_isascii(format[i]) && !(ft_strchr(RES, format[i])))
			break ;
		if ((ft_isalpha(format[i]) == 1) && (ft_strchr(CONV, format[i])))
			break ;
		i++;
	}
	if (format[i])
		pf->format = ft_strsub(format, 0, i + 1);
	else if (format[i] == '\0')
		pf->format = ft_strsub(format, 0, i);
	pf_fill(pf);
	if (format[i] == '\0')
		return (format + i);
	return (format + i + 1);
}

int		pf_parse_arg(t_pf *pf, va_list *ap, char **s, void *func[])
{
	int		i;

	i = ft_strchr(CONV, pf->conv) - CONV;
	if (pf->star)
		pf_find_star(ap, pf);
	if (pf->format[ft_strlen(pf->format) - 1] == ' ')
		pf->conv = '\0';
	if (pf->conv)
		pf_find_func(ap, pf, func[i], s);
	return (ft_strlen(pf->format) + 1);
}

int		pf_is_empty(char *format, char **s, int *ans)
{
	int		i;

	i = 0;
	while (format[i] != '%' && format[i])
	{
		if (format[i] == '{')
		{
			i += pf_find_color(format + i, s, ans);
			if (format[i] == '\0')
				break ;
		}
		(*s)[(*ans)++] = format[i];
		i++;
	}
	return (i);
}
