#include <iostream>

struct time
{
	int hours;
	int mins;
};

time sum(time a,time b);
void display(time a);
int main()
{
	using namespace std;
	time day1={5,45};
	time day2 = {4,55};
	time trip = sum(day1,day2);
	display(trip);
	system("pause");
	return 0;
}

time sum(time a,time b)
{
	time c={0,0};
	if((a.mins+b.mins)>=60) {
		c.mins = a.mins + b.mins - 60;
		c.hours = a.hours + b.hours + 1;
	} else {
		c.mins = a.mins + b.mins;
		c.hours = a.hours + b.hours;
	}
	return c;	
}
void display(time a)
{
	std::cout << "time is : " << a.hours << " hours , "<< a.mins << " mins .";
}