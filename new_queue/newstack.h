#ifndef NEWSTACK_H_
#define NEWSTACK_H_

typedef int Item;

class NewStack
{
private:
	static const int MAX = 10; //静态常量
	Item items[MAX];
	int top;
public:
	NewStack();
	~NewStack();
	bool isempty() const; //函数名后的const表示函数不能修改对象内的任何成员
	bool isfull() const;
	bool push(const Item &item);
	bool pop(Item & item);
	int size() const;
	Item topitem() const;
};

#endif