#ifndef __STACK
#define __STACK

#include <stdlib.h>
#include <string.h>
#include "log.h"
#include "bool.h"

#define STACK_MAX_SIZE	100

typedef struct{
	void *base;
	void *top;
	int elem_size;
}STACK;

STACK* stack_creat(int element_size);
void stack_destroy(STACK *s);
STACK* stack_push(STACK *s, void *elem);
STACK* stack_pop(STACK *s, void *elem);
STACK* stack_get_top(STACK *s, void *elem);
BOOL is_full(STACK *s);
BOOL is_empty(STACK *s);
void stack_map(STACK *s, void (*format)(void *));

#endif
