#include <iostream>
#include <cstring>

using namespace std;
struct stringy{
	char * str;
	int ct;
};
void set(stringy & , char *);
void show(const stringy &, int temp = 1 );
void show(const char * , int temp = 1);

int main()
{
	stringy beany;
	char testing[] = "Reality is not what it used to be.";

	set(beany, testing);
	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done!");
	system("pause");
	//delete [] beany.str;
	return 0;
}

void set(stringy & Str, char * ps)
{
	Str.ct = strlen(ps);
	Str.str = new char[Str.ct + 1];
	//Str.str = ps;//”÷tm∑∏’‚÷÷¥ÌŒÛ
	strcpy(Str.str, ps);
}

void show(const stringy & Str, int temp)
{
	for(int i = 0; i < temp; i ++)
	{
		cout << Str.str << endl;
	}
}

void show(const char * Str, int temp)
{
	for(int i = 0; i < temp; i ++)
	{
		cout << Str << endl;
	}
}