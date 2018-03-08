/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:40:53 by user00            #+#    #+#             */
/*   Updated: 2018/01/17 13:40:56 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf(char const *format, ...)
{
	int			ans;
	va_list		ap;

	va_start(ap, format);
	ans = ft_vdprintf(1, format, ap);
	va_end(ap);
	return (ans);
}

int		ft_dprintf(int fd, char const *format, ...)
{
	int		ans;
	va_list ap;

	va_start(ap, format);
	ans = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (ans);
}

int		ft_vdprintf(int fd, char const *format, va_list ap)
{
	int		ans;
	char	*s;

	ans = ft_vasprintf(&s, format, ap);
	write(fd, s, ans);
	free(s);
	return (ans);
}

int		ft_vasprintf(char **s, char const *format, va_list ap)
{
	int		ans;

	ans = pf_func_arr(ft_strdup(format), ap, s);
	return (ans);
}
