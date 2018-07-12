#include "newstack.h"
#include "newqueue.h"
#include <stdio.h>

NewQueue::NewQueue()
{
	Qtop = 0;
	printf("队列被创建...\n");
}

NewQueue::~NewQueue()
{
	Qtop = 0;
}

bool NewQueue::isempty() const //函数名后的const表示函数不能修改对象内的任何成员
{
	return 0 == Qtop;
}

bool NewQueue::isfull() const
{
	return MAX == Qtop;
}

bool NewQueue::enqueue(const Item &item)
{
	if (s1.isfull() != true)
	{
		s1.push(item);
		Qtop++;
		return true;
	}
	return false;
}

bool NewQueue::dequeue(Item &item)
{
	if (s1.isempty() != true)
	{
		//s1倒入s2
		Item temp;
		while (s1.size() > 1)
		{
			s1.pop(temp);
			s2.push(temp);
		}
		//item 置为 s1最后一个元素
		s1.pop(item);
		//s2倒入s1

		while (!s2.isempty())
		{
			s2.pop(temp);
			s1.push(temp);
		}
		Qtop--;
		return true;
	}
	return false;
}