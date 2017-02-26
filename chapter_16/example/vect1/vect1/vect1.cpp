#include <iostream>
#include <string>e
#include <vector>

const int NUM = 5;
int main()
{
	using std::vector;
	using std::string;
	using std::cin;
	using std::cout;
	using std::endl;
	vector<int> ratings(NUM);
	vector<string> title(NUM);
	cout << "You will do exactly as told, you will enter \n" << NUM << " book titles and yout ratings (0-10). \n";
	int i;
	for( i = 0; i < NUM ; i++)
	{
		cout << "Enter title #" << i + 1 << ": ";
		getline(cin, title[i]);
		cout << "Enter your ratings (0-10) : ";
		cin >> ratings[i];
		cin.get();
	}

	cout << "Thank you , you entered the following : \n"<< "rating\t Book \n";
	for( i = 0; i < NUM; i++)
	{
		cout << ratings[i] << "\t" << title[i] << endl;
	}

	system("pause");
	return 0;
}