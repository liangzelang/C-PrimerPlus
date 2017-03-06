#include <iostream>
#include <string>
using namespace std;

struct CandyBar{
	string band;
	double weight;
	int calory;
};
void CreateCandyBar(CandyBar & temp, char *, double, int);
void Show(const CandyBar & temp);

int main()
{
	char * ps = "Millennium Munch";
	double weight_temp = 2.85;
	int y = 350;
	CandyBar candy;
	CreateCandyBar(candy, ps, weight_temp, y);
	Show(candy);
	system("pause");
	return 0;
}

void CreateCandyBar(struct CandyBar & temp, char * ps, double weight, int calory)
{
	temp.band = ps;
	temp.weight = weight;
	temp.calory = calory;
}

void Show(const CandyBar & temp)
{
	cout << "Name: " << temp.band << "\nWeight: " << temp.weight << "\nCalory: " << temp.calory << endl;
}
