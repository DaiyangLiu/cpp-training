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
		//������״ֱ̬����Ϊ0 ��Ȼ��ֱ�ӽ���ѹ���ջ����������0�ı���
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
	case 0: //ũ�򵥶�����
		status[0] = status[0] + 1;
		break;
	case 1://ũ���ǹ���
		status[0] = status[0] + 1;
		status[1] = status[1] + 1;
		break;
	case 2://ũ�������
		status[0] = status[0] + 1;
		status[2] = status[2] + 1;
		break;
	case 3://ũ�򡢲˹���
		status[0] = status[0] + 1;
		status[3] = status[3] + 1;
		break;
	case 4://ũ�򷵻�
		status[0] = status[0] - 1;
		break;
	case 5://ũ���Ƿ���
		status[0] = status[0] - 1;
		status[1] = status[1] - 1;
		break;
	case 6://ũ���򷵻�
		status[0] = status[0] - 1;
		status[2] = status[2] - 1;
		break;
	case 7://ũ�򡢲˷���
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
		//ֻҪ״̬����һ�����Ϸ�����С��0�����1�������жϸ�״̬Ϊ���Ϸ�״̬
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