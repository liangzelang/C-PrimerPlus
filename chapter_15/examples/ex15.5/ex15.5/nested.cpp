// nested.cpp -- using a queue that has a nested class
#include <iostream>
#include <string>
#include "queuetp.h"

int main()
{
	using namespace std;
	QueueTP<string> cs(5);
	string temp;
	while(!cs.isfull())
	{
		cout << "name: \n";
		getline(cin, temp);
		cs.enqueue(temp);
	}
	cout << "full, Processing begins!\n";

	while(!cs.isempty())
	{
		cs.dequeue(temp);
		cout << "Now processing " << temp << "\n";

	}
	system("pause");
	return 0;
}