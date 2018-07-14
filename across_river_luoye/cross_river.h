#ifndef __CROSS_RIVER
#define __CROSS_RIVER

#include "stack.h"
#include "bool.h"
#include "log.h"

#ifndef GLOBAL
#define EX
#else
#define EX 	extern
#endif

#define FARMER	0x01
#define SHEEP	0x02
#define WOLF	0x04
#define CABBAGE	0x08

#define START_STATE	0x0F
#define	END_STATE	0x00
#define ALL_STATE	0x0F

EX unsigned char record[ALL_STATE];
EX STACK *stack;

void cross_river();
void take_boat();
BOOL is_safe(unsigned char state);
void fromat_print(void *p);


#endif
