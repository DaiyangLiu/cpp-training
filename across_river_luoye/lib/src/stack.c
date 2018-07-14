#include "stack.h"

STACK* stack_creat(int element_size){
	STACK* p = (STACK*)malloc(sizeof(STACK));
	if(p == NULL){
		LOG(LOG_ERROR, "not enough memory");
	}
	p->base = malloc(element_size*STACK_MAX_SIZE);
	if(p->base == NULL){
		LOG(LOG_ERROR, "not enough memory");
	}
	p->top = p->base;
	p->elem_size = element_size;
	return p;
}

void stack_destroy(STACK *s){
	s->top = NULL;
	free(s->base);
	free(s);
}

STACK* stack_push(STACK *s, void *elem){
	if(is_full(s)){
		LOG(LOG_ERROR, "stack if full");
		return NULL;
	}
	memcpy(s->top, elem, s->elem_size);
	s->top += s->elem_size;
	return  s;
}

STACK* stack_pop(STACK *s, void *elem){
	if(is_empty(s)){
		LOG(LOG_ERROR, "stack if empty");
		return NULL;
	}
	s->top -= s->elem_size;
	memcpy(elem, s->top, s->elem_size);
	return s;
}

STACK* stack_get_top(STACK *s, void *elem){
	if(is_empty(s)){
		LOG(LOG_ERROR, "stack if empty");
		return NULL;
	}
	void *p = s->top - s->elem_size;
	memcpy(elem, p, s->elem_size);
	return s;
}

BOOL is_full(STACK *s){
	if(s->top == s->base+(s->elem_size*STACK_MAX_SIZE)){
		return TRUE;
	}
	return FALSE;
}

BOOL is_empty(STACK *s){
	if(s->top == s->base){
		return TRUE;
	}
	return FALSE;
}

void stack_map(STACK *s, void (*format)(void *)){
	void *p = s->base;
	for(; p!=s->top; p+=s->elem_size){
		format(p);
	}
}
