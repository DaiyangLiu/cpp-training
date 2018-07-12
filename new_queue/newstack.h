#ifndef NEWSTACK_H_
#define NEWSTACK_H_

typedef int Item;

class NewStack
{
private:
	static const int MAX = 10; //��̬����
	Item items[MAX];
	int top;
public:
	NewStack();
	~NewStack();
	bool isempty() const; //���������const��ʾ���������޸Ķ����ڵ��κγ�Ա
	bool isfull() const;
	bool push(const Item &item);
	bool pop(Item & item);
	int size() const;
	Item topitem() const;
};

#endif