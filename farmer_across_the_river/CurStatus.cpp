#include "curstatus.h"
#include <memory>
#include <iostream>
using namespace std;

CurStatus::CurStatus()
{
	status_num = 0;
	memset(status, -1, sizeof(status));
	//cout << "common" << endl;
}
CurStatus::CurStatus(bool root)
{
	if (root == true)
	{
		//将运算状态直接置为0 ，然后直接将其压入堆栈，进行运算0的遍历
		status_num = 0;  
		memset(status, 0, sizeof(status));
		//cout << "root" << endl;
	}
	else
	{
		status_num = -1;
		memset(status, -1, sizeof(status));
		//cout << "common" << endl;
	}
}

CurStatus::~CurStatus()
{
}

void CurStatus::ChangeStatus(int flag)
{
	status_num = flag;

	switch (status_num)
	{
	case 0: //农夫单独过河
		status[0] = status[0] + 1;
		break;
	case 1://农夫、狼过河
		status[0] = status[0] + 1;
		status[1] = status[1] + 1;
		break;
	case 2://农夫、羊过河
		status[0] = status[0] + 1;
		status[2] = status[2] + 1;
		break;
	case 3://农夫、菜过河
		status[0] = status[0] + 1;
		status[3] = status[3] + 1;
		break;
	case 4://农夫返回
		status[0] = status[0] - 1;
		break;
	case 5://农夫、狼返回
		status[0] = status[0] - 1;
		status[1] = status[1] - 1;
		break;
	case 6://农夫、羊返回
		status[0] = status[0] - 1;
		status[2] = status[2] - 1;
		break;
	case 7://农夫、菜返回
		status[0] = status[0] - 1;
		status[3] = status[3] - 1;
		break;
	default:
		break;
	}
}

bool CurStatus::CheckStatus()
{
	bool qualify = true;

	for (int i = 0; i < 4; i++)
	{
		//只要状态中有一个不合法（即小于0或大于1），就判断该状态为不合法状态
		if (status[i]>1 || status[i] < 0) 
		{
			qualify = false;
			break;
		}
	}
	return qualify;
}

CurStatus CurStatus::operator = (const CurStatus& b)
{
	for (int i = 0; i < 4; i++)
	{
		this->status[i] = b.status[i];
	}
	return this;
}