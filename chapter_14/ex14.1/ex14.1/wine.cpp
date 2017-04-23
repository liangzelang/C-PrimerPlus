#ifndef WINE_H_
#define WINE_H_
#include <string>
#include <iostream>
#include <valarray>

using namespace std;

template <class T1, class T2>
class Pair
{
private:
	T1 year;
	T2 bottles;
public:
	Pair(const T1 & yr, const T2 & bt) : year(yr), bottles(bt) {}
	Pair() {}
	void Set(const T1 & yr, const T2 & bt);
	int Sum() const;
	void Show(int y) const;
};

template <class T1, class T2>
void Pair<T1, T2>::Set(const T1 & yr, const T2 & bt)
{
	year = yr;
	bottles = bt;
}

template <class T1, class T2>
int Pair<T1, T2>::Sum() const
{
	return bottles.sum;  //why
}

template <class T1, class T2>
void Pair<T1, T2>::Show(int y) const
{
	for(int i = 0; i < y; i++)
		cout << "\t" << year[i] << "\t" << bottles[i] << endl;
}

typedef valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine
{};
class Wine
{
private:
	string name;


};

#endif