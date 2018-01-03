#include "ft_printf.h"

int 		ft_printf(const char *format, ...)
{
	t_printff		fl;
    va_list         vl;
    const char      *pos = format;

    va_start(vl, format);
	// TODO:	check is a format string manually ordered, if yes - call
	//			ft_lv_orderprintf
	//ft_lv_orderprintf();

    // TODO correct error exit & call
    pos = ftprt_set_flags(&fl, pos);
    //while () {
        // TODO write
    //}

    // TODO write

    va_end(vl);
}