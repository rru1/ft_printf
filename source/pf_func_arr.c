/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_func_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 14:17:04 by user00            #+#    #+#             */
/*   Updated: 2018/01/17 14:17:06 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**pf_func_init(void **func)
{
	func[0] = &pf_conv_c;
	func[1] = &pf_conv_wc;
	func[2] = &pf_conv_s;
	func[3] = &pf_conv_ws;
	func[4] = &pf_conv_d;
	func[5] = &pf_conv_ld;
	func[6] = &pf_conv_i;
	func[7] = &pf_conv_o;
	func[8] = &pf_conv_lo;
	func[9] = &pf_conv_u;
	func[10] = &pf_conv_lu;
	func[11] = &pf_conv_x;
	func[12] = &pf_conv_lx;
	func[13] = &pf_conv_p;
	func[14] = &pf_conv_f;
	func[15] = &pf_conv_bf;
	func[16] = &pf_conv_e;
	func[17] = &pf_conv_be;
	func[18] = &pf_conv_a;
	func[19] = &pf_conv_ba;
	func[20] = &pf_conv_g;
	func[21] = &pf_conv_bg;
	func[22] = &pf_conv_n;
	return (func);
}

int		pf_func_arr(char *format, va_list ap, char **s)
{
	int			ans;
	void		**functions;

	functions = (void **)malloc(sizeof(void *) * 23);
	pf_func_init(functions);
	ans = pf_parse_format(format, ap, s, functions);
	ft_strdel(&format);
	free(functions);
	return (ans);
}
