// tmp2tmp.cpp -- template friends to a template class
#include <iostream>
using namespace std;

//template prototypes
template <typename T> void counts();
template <typename T> void report(T &);

//template class
template <typename T>
class HasFriend
{
private:
	T item;
	static int ct;
public:
	HasFriend(const T & i) : item(i) { ct++; }
	~HasFriend() { ct--; }
	friend void counts<T>();
	friend void report<>(HasFriend<T> & );
};

template <typename T>
int HasFriend<T>::ct = 0;

//template friend functions definitions
template <typename T>
void counts()
{
	cout << "template size : " << sizeof(HasFriend<T>) << " ; " << "template counts(): " << HasFriend<T>::ct << endl;
}

template <typename T>
void report(T & hf)
{
	cout << hf.item << endl;
}

int main()
{
	counts<int>();
	HasFriend<int> hfi1(10);
	HasFriend<int> hfi2(20);
	HasFriend<double> hfdb(10.5);
	report(hfi1);
	report(hfi2);
	report(hfdb);
	cout << "counts<int>() output : \n" ;
	counts<int>();
	cout << "counts<double>() output: \n";
	counts<double>();
	system("pause");
	return 0;
}    