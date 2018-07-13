#ifndef CURSTATUS_H_
#define CURSTATUS_H_

class CurStatus
{
public:
	//������ 0 1 2 3 �ֱ���� ũ�� �� �� �ײ�
	int status[4];  //������ֵ 0 1 ��ʾ�������0 ��ʾδ���ӣ� 1 ��ʾ���ӡ�
	int status_num; //��ǰ���� �� ״̬���
	//int last_step; //���ڵ��״̬���

	CurStatus();
	CurStatus(bool root);
	~CurStatus();

	void ChangeStatus(int flag);//���������ţ���Ч��λ 0-7
	bool CheckStatus();
	bool CheckSuccess();

	CurStatus operator=(const CurStatus& b);
};

#endif