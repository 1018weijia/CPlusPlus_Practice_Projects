#pragma once
#include<ctime>
//定义定时器类,为了解决在更改按钮数字时频率过高的现象
class Timer
{
public:
	static bool my_Timer(int duration, int id)
	{
		static int startTime[10] = { 0 };//初始化
		int endTime = clock();
		if (endTime - startTime[id] > duration)
		{
			startTime[id] = endTime;
			return true;
		}
		return false;
	}
};