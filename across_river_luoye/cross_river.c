#define GLOBAL
#include "cross_river.h"

void cross_river(){
	int i;
	unsigned char start = START_STATE;
	stack = stack_creat(sizeof(unsigned char));
	stack_push(stack, &start);
	for(i=0; i<ALL_STATE; i++){
		record[i] = 0;
	}
	LOG(LOG_INFO, "search start");
	take_boat();
	LOG(LOG_INFO, "search end");
	stack_destroy(stack);
}

void take_boat(){
	unsigned char cur_state, next_state, passenger;
	if(!is_empty(stack)){
		stack_get_top(stack, &cur_state);
		if(cur_state == END_STATE){
			LOG(LOG_INFO, "find a method");
			stack_map(stack, fromat_print);
		}
		else{
			for(passenger=FARMER; passenger<=CABBAGE; passenger<<=1){
				next_state = cur_state^(FARMER|passenger);
				if(is_safe(next_state) && !record[next_state]){
					record[next_state] = 1;
					stack_push(stack, &next_state);
					take_boat();
				}
			}			
		}
		record[cur_state] = 0;
		stack_pop(stack, &cur_state);
	}
}

BOOL is_safe(unsigned char state){
	if( ((state&SHEEP)!=0)==((state&CABBAGE)!=0) && ((state&SHEEP)!=0)!=((state&FARMER)!=0) ){
		return FALSE;
	}
	if( ((state&SHEEP)!=0)==((state&WOLF)!=0) && ((state&WOLF)!=0)!=((state&FARMER)!=0) ){
		return FALSE;
	}
	return TRUE;
}

void fromat_print(void *p){
	printf("%x\n", *(unsigned char *)p);
}
