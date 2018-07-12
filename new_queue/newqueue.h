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
	bool isempty() const; //函数名后的const表示函数不能修改对象内的任何成员
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