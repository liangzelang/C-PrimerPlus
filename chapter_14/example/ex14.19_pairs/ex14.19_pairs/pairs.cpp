// pairs.cpp -- defining and using a Pair template
#include <iostream>
#include <string>

using namespace std;

template <class T1, class T2>
class Pair
{
private:
	T1 a;
	T2 b;
public:
	T1 & first();
	T2 & second();
	T1 first() const { return a;}
	T2 second() const {return b;}
	Pair(const T1 & aval, const T2 & bval) : a(aval), b(bval) {}
	Pair() {}
};

template <class T1, class T2>
T1 & Pair<T1, T2>::first()
{
	return a;
}

template <class T1, class T2>
T2 & Pair<T1, T2>::second()
{
	return b;
}

int main()
{
	Pair<string, int> rating[4] = {
	Pair<string, int>("lzl", 5),
	Pair<string, int>("liang", 4),
	Pair<string, int>("ze", 3),
	Pair<string, int>("lang", 6)
	};
	int joints = sizeof(rating) / sizeof(Pair<string, int>);
	cout << "Rating : \tEatery\n";
	for(int i = 0; i < joints; i++)
	{
		cout << rating[i].second() << " : " << rating[i].first() << endl;
	}
	cout << "Oops! Revise rating: \n ";
	rating[3].first() = "Fuck";
	rating[3].second() = 6;
	cout << rating[3].second() << " : \t" << rating[3].first() << endl;
	system("pause");
	return 0;
}
