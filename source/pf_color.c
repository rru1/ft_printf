/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:41:12 by user00            #+#    #+#             */
/*   Updated: 2018/01/17 13:41:15 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		pf_find_color(char *format, char **s, int *ans)
{
	char	**colors;
	char	**vcol;
	int		i;
	int		j;

	i = 0;
	j = 0;
	colors = pf_create_color();
	while (colors[i])
	{
		if (pf_strfstr(format, colors[i]))
		{
			vcol = pf_get_color();
			while (vcol[i][j])
				(*s)[(*ans)++] = vcol[i][j++];
			pf_free_arr2(vcol);
			free(vcol);
			return (ft_strlen(colors[i]));
		}
		i++;
	}
	pf_free_arr2(colors);
	free(colors);
	return (0);
}

char	**pf_get_color(void)
{
	char **vcol;

	vcol = (char **)malloc(sizeof(char *) * 17);
	vcol[0] = ft_strdup("\x1b[31m");
	vcol[1] = ft_strdup("\x1b[32m");
	vcol[2] = ft_strdup("\x1b[33m");
	vcol[3] = ft_strdup("\x1b[34m");
	vcol[4] = ft_strdup("\x1b[35m");
	vcol[5] = ft_strdup("\x1b[36m");
	vcol[6] = ft_strdup("\x1b[37m");
	vcol[7] = ft_strdup("\x1b[30m");
	vcol[8] = ft_strdup("\x1b[41m");
	vcol[9] = ft_strdup("\x1b[42m");
	vcol[10] = ft_strdup("\x1b[43m");
	vcol[11] = ft_strdup("\x1b[44m");
	vcol[12] = ft_strdup("\x1b[45m");
	vcol[13] = ft_strdup("\x1b[46m");
	vcol[14] = ft_strdup("\x1b[47m");
	vcol[15] = ft_strdup("\x1b[40m");
	vcol[16] = ft_strdup("\x1b[0m");
	vcol[17] = NULL;
	return (vcol);
}

char	**pf_create_color(void)
{
	char **colors;

	colors = (char **)malloc(sizeof(char *) * 17);
	colors[0] = ft_strdup("{red}");
	colors[1] = ft_strdup("{green}");
	colors[2] = ft_strdup("{yellow}");
	colors[3] = ft_strdup("{blue}");
	colors[4] = ft_strdup("{magenta}");
	colors[5] = ft_strdup("{cyan}");
	colors[6] = ft_strdup("{white}");
	colors[7] = ft_strdup("{black}");
	colors[8] = ft_strdup("{red|b}");
	colors[9] = ft_strdup("{green|b}");
	colors[10] = ft_strdup("{yellow|b}");
	colors[11] = ft_strdup("{blue|b}");
	colors[12] = ft_strdup("{magenta|b}");
	colors[13] = ft_strdup("{cyan|b}");
	colors[14] = ft_strdup("{white|b}");
	colors[15] = ft_strdup("{black|b}");
	colors[16] = ft_strdup("{eoc}");
	colors[17] = NULL;
	return (colors);
}
