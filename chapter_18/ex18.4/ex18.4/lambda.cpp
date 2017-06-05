//using lambda function
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

auto outint = [](int n) { cout << n << ", ";};

int main()
{
	int vals[10] = { 11,220,346,4,56,6,667,8,966,140};
	list<int> ya(vals, vals+10);
	list<int> et(vals, vals+10);
	cout << "Original lists: \n";
	for_each(ya.begin(), ya.end(), outint);
	cout << endl;
	for_each(et.begin(), et.end(), outint);
	cout << endl;

	ya.remove_if([](int n){return n > 100;});
	et.remove_if([](int n){return n > 200;});

	cout << "After: \n";
	for_each(ya.begin(), ya.end(), outint);
	cout << endl;

	for_each(et.begin(), et.end(), outint);
	cout << endl;

	system("pause");
	return 0;
}