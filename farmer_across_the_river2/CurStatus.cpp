#include "curstatus.h"
#include <memory>
#include <iostream>
using namespace std;

CurStatus::CurStatus()
{
	status_num = 0;
	//last_step = 0;
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

CurStatus CurStatus::ChangeStatus(int flag)
{
	status_num = flag;
	CurStatus c=*this;

	switch (flag)
	{
	case 0: //农夫单独过河
		c.status[0] = this->status[0] + 1;
		//cout << "农夫单独过河" << endl;
		break; 
	case 1://农夫、狼过河
		c.status[0] = this->status[0] + 1;
		c.status[1] = this->status[1] + 1;
		//cout << "农夫、狼过河" << endl;
		break;
	case 2://农夫、羊过河
		c.status[0] = this->status[0] + 1;
		c.status[2] = this->status[2] + 1;
		//cout << "农夫、羊过河" << endl;
		break;
	case 3://农夫、菜过河
		c.status[0] = this->status[0] + 1;
		c.status[3] = this->status[3] + 1;
		//cout << "农夫、菜过河" << endl;
		break;
	case 4://农夫返回
		c.status[0] = this->status[0] - 1;
		//cout << "农夫返回" << endl;
		break;
	case 5://农夫、狼返回
		c.status[0] = this->status[0] - 1;
		c.status[1] = this->status[1] - 1;
		//cout << "农夫、狼返回" << endl;
		break;
	case 6://农夫、羊返回
		c.status[0] = this->status[0] - 1;
		c.status[2] = this->status[2] - 1;
		//cout << "农夫、羊返回" << endl;
		break;
	case 7://农夫、菜返回
		c.status[0] = this->status[0] - 1;
		c.status[3] = this->status[3] - 1;
		//cout << "农夫、菜返回" << endl;
		break;
	default:
		break;
	}

	return c;
}

bool CurStatus::CheckStatus()
{
	bool qualify = true;

	//只要状态中有一个不合法（即小于0或大于1），就判断该状态为不合法状态
	for (int i = 0; i < 4; i++)
	{
	
		if (status[i]>1 || status[i] < 0) 
		{
			qualify = false;
			break;
		}
	}

	//判断状态是否回到根节点
	int tag = 0;
	for (int i = 0; i < 4; i++)
	{
		if (status[i]== 0)
		{
			tag++;
		}
	}
	if (tag == 4)
	{
		qualify = false;
	}

	//判断狼羊、羊菜是否在一边
	if (status[1] == status[2] && status[0] != status[1])
	{
		qualify = false;
	}
	if (status[3] == status[2] && status[0] != status[3])
	{
		qualify = false;
	}

	return qualify;
}
bool CurStatus::CheckSuccess()
{
	bool success = true;
	for (int i = 0; i < 4; i++)
	{
		if (status[i] != 1)
		{
			success = false;
			break;
		}
	}
	return success;
}

CurStatus CurStatus::operator = (const CurStatus& b)
{
	for (int i = 0; i < 4; i++)
	{
		this->status[i] = b.status[i];
	}

	return this;
}

bool  CurStatus::operator==(const CurStatus& b)
{
	bool tag = true;
	for (int i = 0; i < 4; i++)
	{
		if (this->status[i] != b.status[i])
		{
			tag = false;
			break;
		}
	}
	return tag;
}