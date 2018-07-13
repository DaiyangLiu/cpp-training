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

CurStatus CurStatus::ChangeStatus(int flag)
{
	status_num = flag;
	CurStatus c=*this;

	switch (flag)
	{
	case 0: //ũ�򵥶�����
		c.status[0] = this->status[0] + 1;
		//cout << "ũ�򵥶�����" << endl;
		break; 
	case 1://ũ���ǹ���
		c.status[0] = this->status[0] + 1;
		c.status[1] = this->status[1] + 1;
		//cout << "ũ���ǹ���" << endl;
		break;
	case 2://ũ�������
		c.status[0] = this->status[0] + 1;
		c.status[2] = this->status[2] + 1;
		//cout << "ũ�������" << endl;
		break;
	case 3://ũ�򡢲˹���
		c.status[0] = this->status[0] + 1;
		c.status[3] = this->status[3] + 1;
		//cout << "ũ�򡢲˹���" << endl;
		break;
	case 4://ũ�򷵻�
		c.status[0] = this->status[0] - 1;
		//cout << "ũ�򷵻�" << endl;
		break;
	case 5://ũ���Ƿ���
		c.status[0] = this->status[0] - 1;
		c.status[1] = this->status[1] - 1;
		//cout << "ũ���Ƿ���" << endl;
		break;
	case 6://ũ���򷵻�
		c.status[0] = this->status[0] - 1;
		c.status[2] = this->status[2] - 1;
		//cout << "ũ���򷵻�" << endl;
		break;
	case 7://ũ�򡢲˷���
		c.status[0] = this->status[0] - 1;
		c.status[3] = this->status[3] - 1;
		//cout << "ũ�򡢲˷���" << endl;
		break;
	default:
		break;
	}

	return c;
}

bool CurStatus::CheckStatus()
{
	bool qualify = true;

	//ֻҪ״̬����һ�����Ϸ�����С��0�����1�������жϸ�״̬Ϊ���Ϸ�״̬
	for (int i = 0; i < 4; i++)
	{
	
		if (status[i]>1 || status[i] < 0) 
		{
			qualify = false;
			break;
		}
	}

	//�ж�״̬�Ƿ�ص����ڵ�
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

	//�ж���������Ƿ���һ��
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