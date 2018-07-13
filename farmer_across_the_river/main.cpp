//failed
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


	//int step=0;

	while (!s.empty())
	{
		temp = s.top();
		temp.status_num = 0;
		//B状态的 status_num = 1
		//temp.ChangeStatus(s.top().status_num);
		temp.ChangeStatus( s.top().status_num);
		
		if (temp.CheckStatus())//状态有效
		{
			s.push(temp);		
			if (s.top().CheckSuccess())
			{
				cout << "ok" << endl;
			}
		}
		else//状态无效
		{
			s.top().status_num++;
			while(s.top().status_num > 7 )
			{
				s.pop();
				if (!s.empty())
				{	
					s.top().status_num++;					
				}
				else
				{
					break;
				}
			}
		}
	}
	
	system("pause");
	return 0; 
}

