CC = gcc
CFLAGS = -O2
LIB = lib
DIRS = $(LIB)/src .
TARGET = cross_river
FILES = $(foreach dir, $(DIRS), $(wildcard $(dir)/*.c))
OBJS = $(patsubst %.c, %.o, $(FILES))

$(TARGET):$(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(CFLAGS) -I$(LIB)/include

$(OBJS):%.o:%.c
	$(CC) -c $< -o $@ $(CFLAGS) -I$(LIB)/include

clean:
	-$(RM) $(TARGET) $(TARGET).o $(TARGET).exe
	-$(RM) $(OBJS)
