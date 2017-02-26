#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "vector.h"

int main()
{
	using namespace std;
	ofstream fout;
	fout.open("thewalk.txt");
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "Enter target distance (q to quit) :";
	while(cin >> target)
	{
		cout << "Enter step length : ";
		if(!(cin >> dstep))
			break;
		while(result.mag_val() < target)
		{
			direction = rand() % 360;
			step.Reset(dstep,direction,Vector::Pol);
			result = result + step;
			fout << result << endl;
			steps++;
		}
		cout << " After   "<< steps << "  steps, the subject has the following location : \n";
		cout << result << endl;
		result.polar_mode();
		cout << " Or ," << result << endl;
		cout << "Average outward distance per step = " << result.mag_val()/steps << endl;
		steps = 0;
		result.Reset(0.0,0.0);
		cout << "Enter target distance (q to quit) :";
	}
	fout.close();
	cout << "Bye . \n";
	cin.clear();   //就是q导致的输入错误，阻塞。
	system("pause");
	return 0;
}