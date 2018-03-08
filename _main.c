	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 09:20:41 by eterman           #+#    #+#             */
/*   Updated: 2016/12/23 13:47:48 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <float.h>

#define TEST1	"% +#-100.100S:\n", wstr
#define TEST2	"% +0#-10.100S:\n", wstr
#define TEST3	"% +#-10.1S:\n", wstr
#define TEST4	"% +#10.10ls:\n", wstr
#define TEST5	"% +#.S:\n", wstr
#define TEST6	"% +#s:\n", wstr
#define TEST7	"% +#s:\n", "wstr"
#define TEST8	"% +#s:\n", NULL
#define TEST9	"%#08x:\n", 42
#define TEST10	"% +#0-12.30u:\n", -53
#define TEST11	"% +#0-12.30x:\n", -53
#define TEST12	"% +#0-12.30X:\n", -53
#define TEST13	"% +#0-12.30o:\n", -53
#define TEST14	"% +#0-12.30lli:\n", -53
#define TEST15	"% +#0-.lli:\n", -53
#define TEST16	":% 0lli:\n", 53
#define TEST17	"% +042.42lli:\n", 53
#define TEST18	"%.2s:\n", NULL
#define TEST19	"% +042.42p:\n", 53
#define TEST20	"% +042.42p:\n", "53"
#define TEST21	"%.lli:\n", 0
#define TEST22	"%.2c:\n", '0'
#define TEST23	"% +#0-12.30d:\n", LLONG_MAX
#define TEST24	"% +#0-12.30d:\n", LLONG_MIN
#define TEST25	"%c:\n", '\300'
#define TEST26	"%s:\n", ""
#define TEST27	"%lls:\n", wstr
#define TEST28	"%hs:\n", wstr
#define TEST29	"%#ls:\n", wstr

#define TEST30	"%-5%:\n"
#define TEST31	"%#-08x:\n", 42
#define TEST32	"@moulitest: %#.x %#.0x\n", 0, 0
#define TEST33	"@moulitest: %5.x %5.0x\n", 0, 0
#define TEST34	"this is a %s\n", "string"
#define TEST35	":%2c:\n", 0
#define TEST36	"%hU", 4294967296
#define TEST37	"@moulitest: %#.o %#.0o", 0, 0
#define TEST38	"%0+.5d", 42
#define TEST39	"@moulitest: %#.x %#.0x", 0, 0

#define TEST40	":%:->::"
#define TEST41	":% :->:: (len+ == 19)"
#define TEST42	":% h:->:: (len+ == 19)"
#define TEST43	":%Z:->:Z: (len+ == 19)"
#define TEST44	":% hZ:->:Z: (len+ == 19)"
#define TEST45	":%05%:->:0000%%:"
#define TEST46	":% hZ%:->:Z:"
#define TEST47	":% Z:", "test"
#define TEST48	":% Z :", "test"
#define TEST49	"% Z%s", "test"
#define TEST50	":%%%:->:%:", "test"
#define TEST51	":%%   %:", "test"
#define TEST52	"%ll#x-->0x7fffffffffffffff<--", 9223372036854775807
#define TEST53	"%010s is a string", "this"
#define TEST54	"%05c", 42
#define TEST55	"% Z", 42
#define TEST56	"%5+d", 42
#define TEST57	"%5+d", -42
#define TEST58	"%-5+d", 42
#define TEST59	"%-5+d", -42
#define TEST60	"%zhd", 4294967296
#define TEST61	"%jzd", 9223372036854775807
#define TEST62	"%jhd", 9223372036854775807
#define TEST63	"%lhl", 9223372036854775807
#define TEST64	"%lhlz", 9223372036854775807
#define TEST65	"%zj", 9223372036854775807
#define TEST66	"%hhld", 128
#define TEST67	"@main_ftprintf: %####0000 33..1..#00d\n", 256
#define TEST68	"@main_ftprintf: %####0000 33..1d", 256
#define TEST69	"@main_ftprintf: %###-#0000 33...12..#0+0d", 256
#define TEST70	"%10x", 42
#define TEST71	"%#-08x", 42
#define TEST72	"%10s is a string", "this"
#define TEST73	"%s%s%s%s%s", "this", "is", "a", "multi", "string"

#define TEST74	"% 03d", 0
#define TEST75	":%*c:", -15, 0
#define TEST76	":%.*s:", 0, "42"
#define TEST77	"%ji", LLONG_MIN
#define TEST78	"%zi", LLONG_MIN
#define TEST79	"%-15c", 0

#define TEST80	"{cl}{#n}{cyan}I {eoc}{bg_rgb$}{black}love{eoc} {rgb208}{$}{b}cookies{eoc} {red}{$}%s\n", 123, "strike", "underscore", "cursus42"
#define TEST81	"{red}{help}{clear}done"
#define TEST82	"% 10.1f\n", -0.55000001

#define TEST	TEST82

#define HEX_BASE "0123456789abcdef"

char		*num_to_base(t_ull n, int base, int is_unsigned, int size)
{
	char	static_buff[100];
	char	*dynamic_buff;
	int		is_neg;
	int		aux;

	dynamic_buff = static_buff + 100;
	*(dynamic_buff--) = 0;
	is_neg = 0;
	if ((signed char)n < 0 && size == sizeof(signed char))
	{
		is_neg = 1;
		n = (signed char)n;
	}
	else if ((short)n < 0 && size == sizeof(short))
	{
		is_neg = 1;
		n = (short)n;
	}
	else if ((int)n < 0 && size == sizeof(int))
	{
		is_neg = 1;
		n = (n << 32) >> 32;
	}
	else if ((long)n < 0 && size == sizeof(long))
	{
		is_neg = 1;
		n = (long)n;
	}
	else if ((long long)n < 0 && size == sizeof(long long))
	{
		is_neg = 1;
		n = (long long)n;
	}
	if (n == 0)
		*(dynamic_buff--) = '0';
	while (n != 0)
	{
		*(dynamic_buff--) = HEX_BASE[n % base];
		n /= base;
	}
	if (is_neg)
		*(dynamic_buff--) = '-';
	return (ft_strdup(dynamic_buff + 1));
}

long long	ft_pow(int n, int power)
{
	long long	rs;

	rs = 1;
	while (power > 0)
	{
		rs *= n;
		power--;
	}
	return (rs);
}


int			main(void)
{
	wchar_t		*wstr = L"Ž€また会いましょう。, そしてまた, じゃあまた明日, では";	
	setlocale(LC_CTYPE, "");

	//ft_printf("{$}emil{eoc}\n", "rgb$",  23);
	ft_fprintf(1, TEST80);
	return (0);
}