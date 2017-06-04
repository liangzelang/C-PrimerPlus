// lambda1.cpp -- use captured variables
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;
const long Size = 390000L;

int main()
{
	vector<int> numbers(Size);
	srand(time(0));
	generate(numbers.begin(), numbers.end(), rand);

	cout << "Sample size = " << Size << endl;
	//using lambda
	int count3 = count_if(numbers.begin(), numbers.end(), [](int x) { return x % 3 == 0;});
	cout << "Count of numbers divisible by 3 : " << count3 << endl;

	int count13 = 0;
	for_each(numbers.begin(), numbers.end(), [&count13](int x) {count13 += x % 13 == 0;});
	cout << "Count of numbers divisible by 13 : " << count13 << endl;

	//using a single lambda
	count3 = count13 = 0;
	for_each(numbers.begin(), numbers.end(), [&](int x) { count3 += x % 3 == 0; count13 += x % 13 ==0;});
	cout << "Count 3 : " << count3 << "\nCount 13 : " << count13 << endl;
	system("pause");
	return 0;
}