#pragma once
#include<ctime>
//���嶨ʱ����,Ϊ�˽���ڸ��İ�ť����ʱƵ�ʹ��ߵ�����
class Timer
{
public:
	static bool my_Timer(int duration, int id)
	{
		static int startTime[10] = { 0 };//��ʼ��
		int endTime = clock();
		if (endTime - startTime[id] > duration)
		{
			startTime[id] = endTime;
			return true;
		}
		return false;
	}
};