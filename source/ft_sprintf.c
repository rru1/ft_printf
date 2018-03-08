/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:41:03 by user00            #+#    #+#             */
/*   Updated: 2018/01/17 13:41:06 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_vsnprintf(char *s, size_t size, char const *format, va_list ap)
{
	char		*str;
	int			ans;

	ans = ft_vasprintf(&str, format, ap);
	ft_strncpy(s, str, size);
	free(str);
	return (ans);
}

int		ft_vsprintf(char *s, char const *format, va_list ap)
{
	char		*str;
	int			ans;

	ans = ft_vasprintf(&str, format, ap);
	ft_strcpy(s, str);
	free(str);
	return (ans);
}

int		ft_asprintf(char **ret, char const *format, ...)
{
	va_list		ap;
	int			ans;

	va_start(ap, format);
	ans = ft_vasprintf(ret, format, ap);
	va_end(ap);
	return (ans);
}

int		ft_snprintf(char *s, size_t size, char const *format, ...)
{
	va_list		ap;
	int			ans;

	va_start(ap, format);
	ans = ft_vsnprintf(s, size, format, ap);
	va_end(ap);
	return (ans);
}

int		ft_sprintf(char *s, char const *format, ...)
{
	va_list		ap;
	int			ans;

	va_start(ap, format);
	ans = ft_vsprintf(s, format, ap);
	va_end(ap);
	return (ans);
}
