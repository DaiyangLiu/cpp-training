#include <stdio.h>
#include <stack>
#include <string>
#include <iostream>
#include <memory>
#include "curstatus.h"
using namespace std;


int main()
{
	stack<CurStatus> s;
	int flag_keeper[20]; //用来保存状态迁移的顺序编号 
	int flag_point = 0;

	memset(flag_keeper, -1, sizeof(flag_keeper));

	CurStatus root(true);//[0,0,0,0] 0
	flag_keeper[0] = 0;
	flag_point++;

	s.push(root); //把根节点压入堆栈
	
	CurStatus temp;

	temp = root;//将root的初始状态赋给temp

	//int status_count = 0;
	while (!s.empty())
	{
		temp.ChangeStatus(s.top().status_num);
		if (temp.CheckStatus())
		{

			s.push(temp);
		}
		else
		{		
			if (s.top().status_num < 7)
			{
				s.top().status_num++;
			}
			else
			{
				s.pop();
				s.top().status_num++;
			}
		}
	}
	
	system("pause");
	return 0; 
}