#include <stdio.h>
#include <stack>
#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include "curstatus.h"
using namespace std;


int main()
{
	stack<CurStatus> s;
	stack<CurStatus> s2;
	vector<CurStatus> status_record;
	
	CurStatus root(true);
	CurStatus temp;
	
	s.push(root);

	while (!s.empty())
	{
		temp = s.top().ChangeStatus(s.top().status_num);
		//for (int i = 0; i < 4; i++)
		//{
		//	cout << temp.status[i] << " ";
		//}
		//cout << endl;
		//状态重复处理
		int is_repeat = 0;
		vector<CurStatus>::iterator it;
		for (it = status_record.begin(); it != status_record.end(); it++)
		{
			if (temp == *it)
			{
				is_repeat = 1;
				break;
			}
		}
		//状态合法判断
		if (temp.CheckStatus() && !is_repeat)
		{			
			cout << "状态合法" << endl;
			status_record.push_back(temp);
			s.push(temp);

			if (s.top().CheckSuccess())
			{
				s2 = s;
				while (!s2.empty())
				{
					//s2.top();
					for (int i = 0; i < 4; i++)
					{
						cout << s2.top().status[i]<<" ";
					}					
					s2.pop();
					cout << endl;
				}
				cout << "----------OK-----------" << endl;
				//status_record.clear();
				//break;
			}
		}
		else
		{
			s.top().status_num++;
			while (s.top().status_num > 7)
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

