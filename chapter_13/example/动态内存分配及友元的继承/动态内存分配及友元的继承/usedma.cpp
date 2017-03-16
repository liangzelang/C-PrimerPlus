// usedma.cpp -- inheritance, friends and DMA
#include <iostream>
#include "dma.h"

using namespace std;

int main()
{
	{baseDMA shirt("Portabelly", 8);
	lacksDMA balloon("red", "Blimpo", 4);
	hasDMA map("Mercator", "Buffalo Keys", 5);
	cout << "Displaying baseDMA object: \n";
	cout << shirt << endl;

	cout << "Displaying lacksDMA object: \n";
	cout << balloon << endl;

	cout << "Displaying hasDMA object: \n";
	cout << map << endl;

	lacksDMA balloon2(balloon);
	cout << "Displaying lacksDMA object: \n";
	cout << balloon2 << endl;

	hasDMA map2;
	map2 = map;
	cout << "Displaying hasDMA object: \n";
	cout << map << endl;}
	

	system("pause");
	return 0;
}