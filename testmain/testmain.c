#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <fcntl.h>
//#include <math.h>
#include "../libftprintf/ft_printf.h"

//void test_va2(t_printff *fll, va_list *arg, int *i)
//{
//    printf("2: %d\n", va_arg(*arg, int));
//}
//
//void test_va3(t_printff *fll, va_list *arg, int *i)
//{
//    printf("3: %d\n", va_arg(*arg, int));
//}
//
//
//void test_va(const char *r, ...)
//{
//	va_list     arg;
//    int 	    temp;
//    t_type_proc a[2];
//
//    a[0] = &test_va2;
//    a[1] = &test_va3;
//
//	va_start(arg, r);
//    temp = va_arg(arg, int);
//	printf("1: %d\n", temp);
//
//	va_end(arg);
//}

int     main()
{
//    TESTING VA
	//test_va("123454534", 34, 45, 56, 76);


//
//	int 	    i = 14248;
//    size_t      lim = 4;
	wchar_t	    a[] = L"ϏϏϏ";
	wchar_t 	cc = L'Ϗ';
//	char        b[] = "d;dϏsi";
//    char        *c = b;
//    wchar_t     *d = a;
    wchar_t     yy[] = {945, 14248, 0};

//    printf("|%S|\n", a);
//    ft_printf("|%S|\n", a);
//
    setlocale(LC_ALL, "");
//
//    printf("|%S|\n", a);
//    ft_printf("|%S|\n", a);
//
    //test_va("123");

//	printf("%C\n", i);
//    //printf("%d\n", i);
//
//    ft_putwchar(i);
//    ft_putwchar_lim(i, &lim);

    //printf("|%'d|\n", 12345678);
    //printf("%s\n", "\'\'\'");
    //printf("|%d|", *(localeconv()->thousands_sep));

    char *test_s = "abbabbab";

    //ft_printf("%%sd|%-9.5s|fsd%%\n", test_s);
    //printf("|%10.3s|", "1234");
    int res_p, res_ftp;

//    res_p = printf("|%*.*ls|\n", -5, 5, a);
//    res_ftp = ft_printf("|%*.*ls|\n", -5, 5, a);
//    printf("%d %d\n", res_p, res_ftp);

//    int ttint = -2147483648;
//    unsigned int uuint = -ttint;

//    char fstr[] = "|%- +08.5lld|\n";
//    long long ivalue = 0;
//    char fstr[] = "|%+0.0lld|\n";
//    long long ivalue = 0;

//    char fstr[] = "|% 12llu|\n";
//    unsigned long long ivalue = 1234567;

	char fstr[] = "|% Test Zoo|\n"; //1.3
	long double dv = 0.99; //0.99
	char *n = NULL;

	//int iii = 42342346
	//int tempin = (int)dv;

//	unsigned long long	mask = 1;
//	mask <<= 12;
//	mask -= 1;
//	mask <<= 52;
//
//	void				*vvaptr = &dv;
//	unsigned long long	*vaptr = vvaptr;
//
//	for (unsigned long long dmask = mask; dmask; dmask >>= 1)
//		printf("%d", dmask & 1);
//	printf("\n");
//
//	unsigned long long res = (*vaptr) & mask;
//
//	for (unsigned long long dmask = *vaptr; dmask; dmask >>= 1)
//		printf("%d", dmask & 1);
//	printf("\n");

	//printf("%u\n", sizeof(double), sizeof(long double), sizeof(uintmax_t));
    //unsigned long long ivalue = (unsigned long long)2 * 1987987978;

	//char t = '1';

    res_p = printf(fstr, n);
    res_ftp = ft_printf(fstr, n);
    printf("%d %d\n", res_p, res_ftp);

//	t_time_t *time = construct_t_time_t_uf(1516457257);
//
//	ft_printf("time: %u %u %u %u %u %u\n", time->year, time->month, time->day,
//		time->hour, time->minute, time->second);
//
//	destruct_t_time_t((const t_time_t **const)&time);
//
//	time_t tb = 15;
//
//	ft_printf("|%100lb|\n", tb);
//	ft_printf("|%'100.*lR|\n", sizeof(tb), &tb);

	long double dv2 = 3434543553453453345346345345645534534645634454.354453453l;
	char fsrt2[] = ">|%LA|\n"; //.5

	res_p = printf(fsrt2, dv2);
	res_ftp = ft_printf(fsrt2, dv2);
	printf("%d %d\n", res_p, res_ftp);
//
//	printf("%Lf -> %f\n", dv2, (double)dv2);
//
//	ft_printf("$= |%3$d %2$d %1$d|\n", 34534, 24, 464);



    return (0);
}
