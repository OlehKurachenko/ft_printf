#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

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

	int 	    i;
	wchar_t	    a[] = L"ϏϏϏ";
	char        b[] = "d;dϏsi";
    char        *c = b;
    wchar_t     *d = a;

	i = printf("%.3S\n", a);

    return (0);
}
