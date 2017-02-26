#include "stack.h"

Stack::Stack()
{
	top = 0;
}

bool Stack::isEmpty() const
{
	return top == 0;
}

bool Stack::isFull() const
{
	return top == Max;
}

bool Stack::push(const unsigned long & a)
{
	if(top < Max) {
		item[top] = a;
		top +=1;
		return true;
	}
	else return false;
}

bool Stack::pop(unsigned long & a)
{
	if(top > 0) {
		a = item[--top];
		return true;
	}
	else return false;
}