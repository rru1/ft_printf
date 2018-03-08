/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 10:27:04 by eterman           #+#    #+#             */
/*   Updated: 2018/03/08 18:51:24 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			nbr_bits(unsigned int nbr)
{
	int				i;

	i = 1;
	while (nbr >> 1)
	{
		nbr = nbr >> 1;
		i++;
	}
	return (i);
}

static void			norm_25ln(char *buff, int *i, unsigned int ch)
{
	buff[(*i)++] = ((ch >> 18) & 7) | 240;
	buff[(*i)++] = ((ch >> 12) & 63) | 128;
}

static void			putwchart(int wchar, int *len, char *buff)
{
	unsigned int	ch;
	int				n;
	int				i;

	i = 0;
	ch = (unsigned int)wchar;
	n = nbr_bits(ch);
	if (n > 7 && ((*len += 1)))
	{
		if (n > 11 && ((*len += 1)))
		{
			if (n > 16 && ((*len += 2)))
				norm_25ln(buff, &i, ch);
			else if ((*len += 1))
				buff[i++] = ((ch >> 12) & 15) | 224;
			buff[i++] = ((ch >> 6) & 63) | 128;
		}
		else if ((*len += 1))
			buff[i++] = ((ch >> 6) & 31) | 192;
		buff[i++] = (ch & 63) | 128;
	}
	else if ((*len += 1))
		buff[i++] = ch;
}

void				ft_putchar_fd(int c, int fd)
{
	char			buff2[10];
	int				len;

	len = 0;
	putwchart(c, &len, buff2);
	buff2[len] = 0;
	write(fd, buff2, len);
}
