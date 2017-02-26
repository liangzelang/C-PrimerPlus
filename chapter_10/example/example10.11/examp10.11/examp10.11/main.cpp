#include <iostream>
#include <cctype>
#include "stack.h"

int main()
{
	using namespace std;
	Stack st;
	char ch;
	unsigned long po;
	cout << "Please enter A to add a purshase order ,\n"<< "P to process a PO, or Q to quit.\n";

	while(cin>>ch && toupper(ch) != 'Q')
	{
		while(cin.get() != '\n')
			continue;
		if(!isalpha(ch)) {
			cout << '\a';
			continue;
		}
		switch(ch)
		{
		case 'A':
		case 'a':
			cout<< "Enter a PO number to add: ";
			cin >> po;
			if(st.isFull()) {
				cout << "stack already full; \n ";
			}
			else st.push(po);
			break;

		case 'P':
		case 'p':
			if(st.isEmpty()) {
				cout << "stack already empty.\n";
			}
			else {
				st.pop(po);
				cout << po << " is poped ";
			}
			break;
		}
		cout << "plese enter A to add a purchase order, "<<"P to process a po, or Q to quit.\n";
	}
	cout << "Bye\n";
	system("pause");
	return 0;
}

