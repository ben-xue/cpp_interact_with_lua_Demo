#include "scriptManager.h"
#include "vtime.h"
#include <time.h>
#include <cstdint>

/*
@brief	: 获取时间；精度，200毫秒
@return	: 10个返回值，时间戳毫秒，时间戳秒，年，月，日，时，分，秒，毫秒，夏令时当前是否生效，返回的不是table
*/
static int LuaGetTime(lua_State* L)
{
	/*test */
	lua_newtable(L);
	struct timeval tp;
	get_timeval(&tp,true);
	struct tm* tm_ptr = localtime(&tp.tv_sec);
	if (tm_ptr)
	{
		// tick, 暂只支持精确到毫秒
		lua_pushnumber(L, (uint64_t)(tp.tv_sec * 1000 + tp.tv_usec * 0.001));
		// 所有秒, 相当于time()
		lua_pushnumber(L, (uint64_t)(tp.tv_sec));
		// 年
		lua_pushnumber(L, tm_ptr->tm_year + 1900);
		// 月
		lua_pushnumber(L, tm_ptr->tm_mon + 1);
		// 日
		lua_pushnumber(L, tm_ptr->tm_mday);
		// 时
		lua_pushnumber(L, tm_ptr->tm_hour);
		// 分
		lua_pushnumber(L, tm_ptr->tm_min);
		// 秒
		lua_pushnumber(L, tm_ptr->tm_sec);
		// 毫秒
		lua_pushnumber(L, tp.tv_usec * 0.001);
		// isdst
		lua_pushnumber(L, tm_ptr->tm_isdst);
/*		cout << (uint64_t)(tp.tv_sec * 1000 + tp.tv_usec * 0.001) <<" "<<(uint64_t)(tp.tv_sec) <<" "<< tm_ptr->tm_year + 1900 <<" "<< tm_ptr->tm_mon + 1 <<" "<< tm_ptr->tm_mday
			<<" "<< tm_ptr->tm_hour <<" "<< tm_ptr->tm_min <<" "<< tm_ptr->tm_sec <<" "<< tp.tv_usec * 0.001 <<" "<< tm_ptr->tm_isdst <<endl;
*/
		return 10;
	}
	return 0;
}

void registerInit()
{
	reg(LuaGetTime);
}