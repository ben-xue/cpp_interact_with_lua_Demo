#include "scriptManager.h"

void scriptManager::registerToLua(const char *funName,lua_CFunction func)
{
	lua_pushcfunction(L,func);
	lua_setglobal(L,funName);
}

// 加载Lua文件到Lua运行时环境中
bool scriptManager::loadLuaFile(lua_State* luaEnv, const string& fileName)
{
	int result = luaL_loadfile(luaEnv, fileName.c_str());
	if (result)
	{
		return false;
	}
	result = lua_pcall(luaEnv, 0, 0, 0);
	if(result != 0){
		puts(lua_tostring(L, -1));
	}
	return result == 0;
}

bool scriptManager::executeFile(const char *filePath)
{
	if(false == luaL_dofile(L,filePath)){
		//执行成功
		return true;
	}else{
		return false;
	}
}

bool scriptManager::Init()
{
	L = luaL_newstate();
	//此处缺省一个lua_panic(),待研究具体用法
	luaL_openlibs(L);

	return executeFile("/home/ubuntu/test/lua/Pro/script/main.lua");
	//return loadLuaFile(L,"/home/ubuntu/test/lua/Pro/script/main.lua");
}
