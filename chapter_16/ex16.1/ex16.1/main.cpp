#include <iostream>
#include <string>
#include <cctype>

using namespace std;
bool isPal(string & st);
int main()
{
	string st;
	cout << "Enter your string : \n";
	getline(cin, st);
	while(cin && st.size() > 0)
	{
		if(isPal(st))
		{
			cout << "Yes it is palindrome.\n";
		}
		else
		{
			cout << "Not palindrome.\n";
		}
		cout << "Enter your next string: \n";
		getline(cin, st);
	}
	system("pause");
	return 0;
}

bool isPal(string & st)
{
	//string str;
	for(int i = st.size()-1 ; i >= 0; i--)     //感觉这是一种取巧的方法，真正的方法应该怎么办呢
	{
		if(isalpha(st[i]))
		{			
			st[i] = tolower(st[i]);
		}
		else
			st.erase(i,1);
	}
	cout << st << endl;

	string rev(st.rbegin(), st.rend());  //construct reversed string
	
	return (rev == st);
}