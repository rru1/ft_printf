/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:26:59 by user00            #+#    #+#             */
/*   Updated: 2018/01/17 13:27:03 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>
# include <stdint.h>

# define RES "# 0-+'*$hljtzLcCsSdDioOuUxXpfFaAeEgGn1234567890."
# define CONV "cCsSdDioOuUxXpfFeEaAgGn"
# define LENGTH "hljtzL"
# define FLAGS "# 0-+'*$"
# define PFS {0,"\0",'\0','\0','\0','\0','\0','c','\0','\0','\0','\0',-1,-1,0}

typedef struct	s_pf
{
	int			va_num;
	char		*format;
	char		apostro;
	char		length;
	char		dollar;
	char		space;
	char		minus;
	char		conv;
	char		hash;
	char		zero;
	char		plus;
	char		star;
	int			precision;
	int			size;
	int			ans;
}				t_pf;

int				ft_printf(char const *format, ...);
int				ft_dprintf(int fd, char const *format, ...);
int				ft_vdprintf(int fd, char const *format, va_list ap);
int				ft_vasprintf(char **s, char const *format, va_list ap);
int				ft_vsnprintf(char *s, size_t size, char const *format,
				va_list ap);
int				ft_vsprintf(char *s, char const *format, va_list ap);
int				ft_asprintf(char **ret, char const *format, ...);
int				ft_snprintf(char *s, size_t size, char const *format, ...);
int				ft_sprintf(char *s, char const *format, ...);

int				pf_func_arr(char *format, va_list ap, char **s);
int				pf_parse_format(char *format, va_list ap, char **s,
				void *func[]);
t_pf			*pf_get_arg(t_pf *pf, char *format, int arg, int ans);
char			*pf_get_format(char *format, t_pf *pf);
int				pf_parse_arg(t_pf *pf, va_list *ap, char **s, void *func[]);
int				pf_is_empty(char *format, char **s, int *ans);
void			pf_free(t_pf *pf);

char			*pf_conv_c(va_list *ap, t_pf *pf);
char			*pf_conv_wc(va_list *ap, t_pf *pf);
char			*pf_conv_wchar(wchar_t w);
char			*pf_conv_s(va_list *ap, t_pf *pf);
char			*pf_conv_ws(va_list *ap, t_pf *pf);
char			*pf_conv_i(va_list *ap, t_pf *pf);
char			*pf_conv_d(va_list *ap, t_pf *pf);
char			*pf_conv_ld(va_list *ap, t_pf *pf);
char			*pf_conv_u(va_list *ap, t_pf *pf);
char			*pf_conv_lu(va_list *ap, t_pf *pf);
char			*pf_conv_o(va_list *ap, t_pf *pf);
char			*pf_conv_lo(va_list *ap, t_pf *pf);
char			*pf_conv_x(va_list *ap, t_pf *pf);
char			*pf_conv_lx(va_list *ap, t_pf *pf);
char			*pf_conv_p(va_list *ap, t_pf *pf);

char			*pf_int_length(intmax_t im, int base, t_pf *pf);
char			*pf_uint_length(uintmax_t im, int base, t_pf *pf);

char			*pf_find_mod(char *s, t_pf *pf);
char			*pf_find_precision(char *s, t_pf *pf);
char			*pf_find_size(char *s, t_pf *pf, char *ptr);
char			*pf_find_flag(char *s, t_pf *pf, int n);
char			*pf_find_apostro(char *str, t_pf *pf);
char			*pf_find_hash(char *s, t_pf *pf);
char			*pf_find_zero(char *s, t_pf *pf, int neg);
void			pf_flag_update(t_pf *pf, int n);

void			pf_fill(t_pf *pf);
char			*pf_update_int(t_pf *pf, char *s, int i);
char			*pf_update_flag(char *s, t_pf *pf);
char			*pf_update_len(char *s, t_pf *pf);
int				pf_update_precision(char *s);

void			pf_find_star(va_list *ap, t_pf *pf);
int				pf_start_value(va_list *ap, t_pf *pf);
void			pf_find_func(va_list *ap, t_pf *pf, char *f(va_list *, t_pf *),
				char **s);

int				pf_find_color(char *format, char **s, int *ans);
char			**pf_get_color(void);
char			**pf_create_color(void);

char			*pf_revstr(char *str);
void			pf_null_char(char *str, t_pf *pf, char **s);
void			pf_free_arr2(char **arr);
int				pf_strfstr(char *b, char *l);
char			*pf_revstr(char *str);
int				pf_alpha_after(char *s);

char			*pf_doubletoa(long double d, char *s, t_pf *pf);
char			*pf_cut_zero(char *s, int len, t_pf *pf);

char			*pf_check_inf(long double f);
char			*pf_get_exp(long double d, char *s, t_pf *pf, int exp);
int				pf_find_exp(long double d);
char			*pf_conv_adv_g(long double d, t_pf *pf, char *s, int exp);
char			*pf_parse_floats(long double d, t_pf *pf);
int				pf_check_nine(long double x, int prec);

char			*pf_conv_n(va_list *ap, t_pf *pf);
char			*pf_conv_be(va_list *ap, t_pf *pf);
char			*pf_conv_e(va_list *ap, t_pf *pf);
char			*pf_conv_f(va_list *ap, t_pf *pf);
char			*pf_conv_bf(va_list *ap, t_pf *pf);

char			*pf_round_dec_string(char *s, int len);
char			*pf_get_rounded_str(long double x, char *s);
long double		pf_round_fraction(long double t);
long double		pf_round_down(long double t);
long double		pf_round_up(long double t);

char			*pf_get_whole_part(long double x, char *s, t_pf *pf);
char			*pf_adv_a(long double d, t_pf *pf, char *s);
char			*pf_cut_zero(char *s, int l, t_pf *pf);
long double		pf_normalize_float(long double x1, int exp);
int				pf_check_normalize(long double x, int p);

char			*pf_conv_a(va_list *ap, t_pf *pf);
char			*pf_conv_ba(va_list *ap, t_pf *pf);
char			*pf_conv_g(va_list *ap, t_pf *pf);
char			*pf_conv_bg(va_list *ap, t_pf *pf);

#endif
