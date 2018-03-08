/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovolcov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:26:46 by ovolcov           #+#    #+#             */
/*   Updated: 2017/11/25 10:59:14 by ovolcov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		split_wn(const char *s, char c)
{
	int count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static int		split_wl(const char *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		i++;
		len++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		t;

	if (!s || !(res = (char **)malloc(sizeof(*res) * (split_wn(s, c) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < split_wn(s, c))
	{
		t = 0;
		if (!(res[i] = ft_strnew(split_wl(&s[j], c) + 1)))
			res[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			res[i][t++] = s[j++];
		res[i][t] = '\0';
	}
	res[i] = NULL;
	return (res);
}
