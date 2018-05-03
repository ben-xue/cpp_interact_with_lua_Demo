#pragma once
#include "../common/luahead.h"
#include "../common/cpphead.h"
#include "../common/singleton.h"

#define scriptManagerObj scriptManager::Instance()
#define reg(fun) scriptManagerObj.registerToLua(#fun,fun)

class scriptManager : public singleton<scriptManager>{
private:
	lua_State *L;
public:
	lua_State * get_L() { return L; }
	bool Init();
	void registerToLua(const char *funName,lua_CFunction func);
	bool executeFile(const char *filePath);
	bool loadLuaFile(lua_State* luaEnv, const string& fileName);
};