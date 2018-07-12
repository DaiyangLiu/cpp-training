#include "newstack.h"
#include "newqueue.h"
#include <stdio.h>

NewQueue::NewQueue()
{
	Qtop = 0;
	printf("���б�����...\n");
}

NewQueue::~NewQueue()
{
	Qtop = 0;
}

bool NewQueue::isempty() const //���������const��ʾ���������޸Ķ����ڵ��κγ�Ա
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
		//s1����s2
		Item temp;
		while (s1.size() > 1)
		{
			s1.pop(temp);
			s2.push(temp);
		}
		//item ��Ϊ s1���һ��Ԫ��
		s1.pop(item);
		//s2����s1

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