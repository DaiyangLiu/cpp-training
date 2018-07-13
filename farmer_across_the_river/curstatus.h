#ifndef CURSTATUS_H_
#define CURSTATUS_H_

class CurStatus
{
public:
	//数组标号 0 1 2 3 分别代表 农夫 狼 羊 白菜
	int status[4];  //数组数值 0 1 表示过河与否，0 表示未过河， 1 表示过河。
	int status_num; //当前辈分 的 状态编号
	//int last_step; //父节点的状态编号

	CurStatus();
	CurStatus(bool root);
	~CurStatus();

	void ChangeStatus(int flag);//输入运算编号，有效数位 0-7
	bool CheckStatus();
	bool CheckSuccess();

	CurStatus operator=(const CurStatus& b);
};

#endif