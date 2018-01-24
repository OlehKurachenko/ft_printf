#include "time_t.h"

static int		z;
static int		era;
static unsigned	doe;
static unsigned yoe;
static unsigned doy;
static unsigned mp;

void destruct_t_time_t(const t_time_t **const ptr_t_time_t)
{
	free((void *)*ptr_t_time_t);
	*ptr_t_time_t = 0;
}

void destruct_const_t_time_t(const t_time_t *const ptr_t_time_t) {
	free((void *)ptr_t_time_t);
}

t_time_t *construct_t_time_t_uf(const time_t unix_time_s) {
	t_time_t		*const res = (t_time_t *)malloc(sizeof(t_time_t));

	res->second = (unsigned int)(unix_time_s % 60);
	res->minute = (unsigned int)((unix_time_s / 60) % 60);
	res->hour = (unsigned int)((unix_time_s / 3600) % 24);
	z = (int)(unix_time_s / 86400 + 719468);
	era = (z >= 0 ? z : z - 146096) / 146097;
	doe = (unsigned)(z - era * 146097);
	yoe = (doe - doe/1460 + doe/36524 - doe/146096) / 365;
	res->year = yoe + era * 400;
	doy = doe - (365*yoe + yoe/4 - yoe/100);
	mp = (5*doy + 2)/153;
	res->day = doy - (153*mp+2)/5 + 1;
	res->month = mp + (mp < 10 ? 3 : -9);
	res->year += (res->month <= 2);
	return (res);
}
