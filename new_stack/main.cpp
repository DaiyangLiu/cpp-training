#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "newstack.h"

int main()
{
	NewStack s1;
	int i=0;

	while (s1.isfull() != true)
	{
		printf("%d is pushed into stack1.\n",i);
		s1.push(i++);
		
	}
	if (s1.isfull() == true)
	{
		printf("stack 1 is full.\n");
	}

	int poptop;
	s1.pop(poptop);
	printf("top element %d is poped.\n", poptop);

	printf("now stack1 has %d elements.\n", s1.size());
	printf("and the top of stack1 is  %d now.\n", s1.topitem());

	printf("and stack1 is preparing to pop all the elements.\n");
	while (s1.isempty() != true)
	{
		s1.pop(poptop);
		printf("top element %d is poped.\n", poptop);
	}
	printf("OK, now the size of stack1 is %d.\n", s1.size());
	system("pause");
	return 0;
}