#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "../libftprintf/ft_printf.h"

//void test_va(const char *r, ...)
//{
//	va_list arg;
//	int 	temp;
//
//	va_start(arg, r);
//
//	while (*(r++))
//	{
//		temp = va_arg(arg, int);
//		printf("%d\n", temp);
//	}
//	va_end(arg);
//}

int     main()
{
//    TESTING VA
	//test_va("123454534", 34, 45, 56, 76);

    setlocale(LC_ALL, "");

	int 	    i = 14248;
    size_t      lim = 4;
	wchar_t	    a[] = L"ϏϏϏ";
	char        b[] = "d;dϏsi";
    char        *c = b;
    wchar_t     *d = a;

//	printf("%C\n", i);
//    //printf("%d\n", i);
//
//    ft_putwchar(i);
//    ft_putwchar_lim(i, &lim);

    printf("|%'d|\n", 12345678);
    //printf("%s\n", "\'\'\'");
    //printf("|%d|", *(localeconv()->thousands_sep));

    return (0);
}
