#include <iostream>	
#include <unistd.h>
#include "./scriptHub/register_to_lua.h"
#include "./scriptHub/scriptManager.h"
#include "./scriptHub/scriptCaller.h"

using std::cout;
using std::endl;

int main(int argc,char **argv)
{
	if( false == scriptManager::Instance().Init() ){
		cout << "error occur!\n";
		puts(lua_tostring(scriptManager::Instance().get_L(), -1));
		return -1;
	}
	registerInit();

	scriptCaller caller(scriptManager::Instance().get_L(),"fun");
	caller += 99;
	caller.Call();

	while(1){
		pause();
	}
	return 0;
}