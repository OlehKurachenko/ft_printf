#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
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

    setlocale(LC_ALL, "");
//
//	int 	    i = 14248;
//    size_t      lim = 4;
	wchar_t	    a[] = L"ϏϏϏ";
//	char        b[] = "d;dϏsi";
//    char        *c = b;
//    wchar_t     *d = a;
    wchar_t     yy[] = {945, 14248, 0};
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

    //res_p = printf("|%*.*ls|\n", -5, 4, a);
    //res_ftp = ft_printf("|%*.*ls|\n", -5, 4, a);
    //printf("%d %d\n", res_p, res_ftp);

    printf("%1$Ld %1$d", -1);


    //printf("|%*.0d|\n", -5, 123);

    return (0);
}
