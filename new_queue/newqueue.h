#ifndef NEWQUEUE_H_
#define NEWQUEUE_H_

#include "newstack.h"

typedef int Item;
//class NewStack;

class NewQueue:public NewStack
{
public:
	NewQueue();
	~NewQueue();
	bool isempty() const; //���������const��ʾ���������޸Ķ����ڵ��κγ�Ա
	bool isfull() const;
	bool enqueue(const Item &item);
	bool dequeue(Item &item);
	
	int size() const;
private:
	NewStack s1, s2;
	static const int MAX = 10;
	int Qtop;
};


#endif