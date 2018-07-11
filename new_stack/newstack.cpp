#include "newstack.h"


NewStack::NewStack()
{
	top = 0;
}

bool NewStack::isempty() const
{
	return 0 == top;
}

bool NewStack::isfull() const
{
	return MAX == top;
}

bool NewStack::push(const Item &item)
{
	if (isfull() != true)
	{
		items[top] = item;
		top++;
		return true;
	}
	return false;
}

bool NewStack::pop(Item & item)
{
	if (isempty() != true)
	{
		item = items[--top];
		return true;
	}
	return false;
}

int NewStack::size() const
{
	return top;
}

Item NewStack::topitem() const
{
	if (top > 0)
	{
		return items[top - 1];
	}
}

NewStack::~NewStack()
{
	top == 0;
}