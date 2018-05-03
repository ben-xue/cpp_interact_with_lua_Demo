#include "vtime.h"
#include <time.h>
#include <sys/time.h>
struct timeval g_cache_tv = { 0 };
time_t g_cache_time_ms = 0;
bool get_timeval(struct timeval* tp, bool force)
{
	if (!tp)
	{
		return false;
	}
	if (force)
	{
		gettimeofday(tp, 0);
		g_cache_tv = *tp;
		g_cache_time_ms = g_cache_tv.tv_sec * 1000 + g_cache_tv.tv_usec / 1000;
		return true;
	}
	tp->tv_sec = g_cache_tv.tv_sec;
	tp->tv_usec = g_cache_tv.tv_usec;
	return true;
}