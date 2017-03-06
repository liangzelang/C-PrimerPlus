#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
	string temp;
	cout << "Enter a string(q to quit): ";
	while( cin >> temp && temp != "q")
	{
		for(int i = 0; i < temp.size(); i++)
		{
			if(islower(temp[i]))
				temp[i] = toupper(temp[i]);
		}
		cout << temp << endl;
		cout << "Enter a string (q to quit): ";
	}
	system("pause");
	return 0;
}