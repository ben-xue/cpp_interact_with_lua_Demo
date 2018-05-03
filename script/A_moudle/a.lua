a = {}

tick = tick or 
{
    -- 间隔200毫秒更新一次
    lua_tick_timestamp = 
    {
        timestamp_msec = 0,     -- 时间戳, 精确到200毫秒
        timestamp_sec = 0,      -- 时间戳, 精确到秒  

        year = 0, 
        month = 0, 
        day = 0, 
        hour = 0, 
        min = 0, 
        sec = 0, 
        msec = 0,
        isdst = 0,
    }
}

-- 更新lua时间戳, 在tick_lua_handle处理1000毫秒的时候调用
function update_lua_tick_timestamp()
    local tmp = tick.lua_tick_timestamp
    tmp.timestamp_msec, tmp.timestamp_sec, tmp.year, tmp.month, tmp.day, tmp.hour, tmp.min, tmp.sec, tmp.msec, tmp.isdst = LuaGetTime()
end


function a.fun(num)
	print("hello,world XXX",num)
end

function fun()
	print("hello,world")
	local tmp = tick.lua_tick_timestamp
    tmp.timestamp_msec, tmp.timestamp_sec, tmp.year, tmp.month, tmp.day, tmp.hour, tmp.min, tmp.sec, tmp.msec, tmp.isdst = LuaGetTime()
    print(tmp.timestamp_msec, tmp.timestamp_sec, tmp.year, tmp.month, tmp.day, tmp.hour, tmp.min, tmp.sec, tmp.msec, tmp.isdst)
    
end

