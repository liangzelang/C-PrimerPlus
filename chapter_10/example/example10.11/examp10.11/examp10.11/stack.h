#ifndef STACK_H_
#define STACK_H_

class Stack
{
private:
	enum{Max = 10};
	unsigned long item[Max];
	int top;
public:
	Stack();   //constructor
	bool isEmpty() const;
	bool isFull() const;
	bool push(const unsigned long & a);      //�����ջ���ͷ���false
	bool pop(unsigned long & a);       //�����ջ�׾ͷ���false
};

#endif 