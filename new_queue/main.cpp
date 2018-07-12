#include <stdio.h>
#include "newstack.h"
#include "newqueue.h"

int main()
{
	NewQueue q;
	Item item;
	for (int i = 0; i < 10; i++)
	{
		q.enqueue(i);
	}

	if (q.enqueue(10))
	{
		printf("the code is wrong.\n");
	}
	else
	{
		printf("the queue is full,can't add another one\n");
	}

	q.dequeue(item);
	printf("front of queue is %d.\n", item);

	while (!q.isempty())
	{
		q.dequeue(item);
		printf("front of queue is %d.\n", item);
	}

	if (q.dequeue(item))
	{
		printf("the code is wrong.\n");
	}
	else
	{
		printf("the queue is empty,can't give another one\n");
	}

	return 0;
}