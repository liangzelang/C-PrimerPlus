#include "tebten.h"
#include <iostream>
using namespace std;

int main()
{
	TableTennisPlayer player1("Zhang", "JK", false);
	RatePlayer rplayer2(1140, "Ma", "long", true);
	rplayer2.Name();
	if(rplayer2.HasTable())
		cout << ": has a table.\n";
	else
		cout << ": hasn`t a table.\n";
	cout << "the Rating is : " << rplayer2.Rating() << endl << endl;

	player1.Name();
	if(player1.HasTable())
		cout << ": has a table.\n";
	else
		cout << ": hasn`t a table.\n";

	RatePlayer rplayer3(1212,player1);
	rplayer3.Name();
	if(rplayer3.HasTable())
		cout << " : has a table.\n";
	else
		cout << " : hasn`t a table. \n";
	cout << rplayer3.Rating() << endl << endl;

	system("pause");
	return 0;
}