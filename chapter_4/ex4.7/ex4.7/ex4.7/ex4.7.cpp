#include <iostream>

struct pizza {
	char company[20];
	float length;
	float weight;
};

void display(const pizza *a)
{
	std::cout<< "Company: " << a->company << "\n";
	std::cout<< "Length: "<< a->length << "\n";
	std::cout<< "Weight:"<< a->weight<<"\n";
} 
int main()
{
	using namespace std;
	pizza *temp = new pizza;
	cout << "enter pizza company : ";
	(cin.get(temp->company,20)).get();
	cout <<"enter pizza length: ";
	cin >> temp->length;
	cout << "enter pizza weight: ";
	cin >> temp->weight;
	display(temp);
	system("pause");
	delete temp;
	return 0;
}