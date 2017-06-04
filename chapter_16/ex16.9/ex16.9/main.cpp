#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <iterator>
#include <algorithm>

using namespace std;
const int Size = 10000;

int main()
{
	clock_t start, end;
	vector<int> vi0(Size);
	list<int> li(Size);
	srand(time(0));
	for (int i = 0; i < Size; i++)
	{
		vi0[i] = rand() % Size;
	}
	copy(vi0.begin(), vi0.end(), back_inserter(li));
	vector<int> vi(vi0);


	start = clock();
	sort(vi.begin(), vi.end());
	end = clock();
	cout << "Time of Sort Vector:" << (double)(end - start) / CLOCKS_PER_SEC << endl;

	start = clock();
	li.sort();  //stl中的sort()函数需要随机访问迭代器，但是list容器不支持这种迭代器，list包含一个基于双向迭代器的sort（）方法
	end = clock();
	cout << "Time of Sort List:" << (double)(end - start) / CLOCKS_PER_SEC << endl;

	copy(vi0.begin(), vi0.end(), back_inserter(li));

	start = clock();
	copy(li.begin(), li.end(), back_inserter(vi));   //对于这个back_inserter()不太了解
	sort(vi.begin(), vi.end());
	copy(vi.begin(), vi.end(), back_inserter(li));
	end = clock();
	cout << "Time of Sort List2:" << (double)(end - start) / CLOCKS_PER_SEC << endl;
	system("pause");
	return 0;
}