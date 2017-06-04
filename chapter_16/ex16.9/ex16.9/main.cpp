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
	li.sort();  //stl�е�sort()������Ҫ������ʵ�����������list������֧�����ֵ�������list����һ������˫���������sort��������
	end = clock();
	cout << "Time of Sort List:" << (double)(end - start) / CLOCKS_PER_SEC << endl;

	copy(vi0.begin(), vi0.end(), back_inserter(li));

	start = clock();
	copy(li.begin(), li.end(), back_inserter(vi));   //�������back_inserter()��̫�˽�
	sort(vi.begin(), vi.end());
	copy(vi.begin(), vi.end(), back_inserter(li));
	end = clock();
	cout << "Time of Sort List2:" << (double)(end - start) / CLOCKS_PER_SEC << endl;
	system("pause");
	return 0;
}