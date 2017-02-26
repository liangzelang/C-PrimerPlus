#include <iostream>

using namespace std;
struct box
{
	char marker[40];
	float height;
	float width;
	float length;
	float volume;
};

void show_Box(const box a)
{
	cout << " marker :" << a.marker << "\n"
		<< " height : "<< a.height << " \n"
		<< " width : " << a.width << "\n"
		<< " length : " << a.length << "\n"
		<< "volume : "<< a.volume << "\n";
}

void calcu_Box(box * a)
{
	a->volume = a->height * a->length * a->width;
}

int main()
{
	box temp = {"temp", 10.1, 10.3, 10.4 ,0 };
	calcu_Box(&temp);
	show_Box(temp);
	system("pause");
	return 0;
}