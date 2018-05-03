#include "scriptCaller.h"

scriptCaller::scriptCaller(lua_State *lState,const char *str) : L(lState),tableName(""),funcName(""),argNum(0)
{
	string func(str);
	size_t found = func.rfind('.');
	if( found != string::npos){
		//table.function的格式
		tableName = func.substr(0,found);
		funcName = func.substr(found+1);
		lua_getglobal(L,tableName.c_str());	//将lua中的表放入栈顶
		if(lua_istable(L,-1)){
			lua_pushstring(L,funcName.c_str());	//函数名入栈
			lua_gettable(L,-2);	//获取table中的函数(放入栈顶)
			lua_remove(L,-2);	//删除table所占据的栈,此时，栈顶的就是table中的函数了.
		}
	}else{
		//function的格式
		funcName = std::move(func);
		int ret = lua_getglobal(L,funcName.c_str());
	}

/*	
	if(ret == 6){
		//函数
		cout << "6 +++: function" <<endl; 
	}else if (ret == 3){
		double num = lua_tonumber(L,-1);
		cout << "3 +++: " << num <<endl;
	}else if(ret == 4){
		const char *str = lua_tostring(L,-1);
		cout << "4 +++: " << str <<endl;
	}else if(ret == 0){
		cout << "0 +++: nil" <<endl; 
	}
*/

}

bool scriptCaller::Call()
{
	cout << "+++++\n";
	if(0 == lua_pcall(L,argNum,0,0)){
		return true;
	}else{
		puts(lua_tostring(L,-1));
		return false;
	}
	static const int STEP_GC_COUNT = 1;
	int ret = 0;
	ret = lua_gc(L, LUA_GCSTEP, STEP_GC_COUNT);
}
