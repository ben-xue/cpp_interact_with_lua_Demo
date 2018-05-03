#pragma once
#include "../common/luahead.h"
#include "../common/cpphead.h"

class scriptCaller{
public:
	scriptCaller(lua_State *L,const char *str);
	bool Call();

	scriptCaller& operator+=(int number)
	{
		lua_pushinteger(L,number);
		argNum += 1;
		return *this;
	}
	
	scriptCaller& operator+=(const char *str)
	{
		lua_pushstring(L,str);
		argNum += 1;
		return *this;
	}

	scriptCaller& operator+=(double num)
	{
		lua_pushnumber(L,num);
		argNum += 1;
		return *this;
	}

	scriptCaller& operator+=(bool flag)
	{
		lua_pushboolean(L,flag);
		argNum += 1;
		return *this;
	}
private:
	lua_State *L;
	string tableName;
	string funcName;
	int argNum;
};