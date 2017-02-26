#include <iostream>


const double * f1(const double ar[], int n);
const double * f2(const double [], int);
const double * f3(const double *, int);

int main()
{
	using namespace std;
	double av[3] = {1.0, 2.0, 3.0};


	//pointer to a function
	const double *(*p1)(const double *,int) = f1;
	auto p2 = p1;

	//using pointers to functions 
	cout << " using pointers to functions : \n";
	cout << " Address Value \n ";
	cout << p1(av,3) << ": " << *p1(av,3) <<endl;
	cout << (*p1)(av,3) << ": " << *(*p1)(av,3) <<endl;
	cout << p2(av,3) << ": "<< *p2(av,3) <<endl;

	//pa an array of pointers
	//auto doesn't work with list initialiaztion
	const double *(*pa[3])(const double *,int ) = {f1,f2,f3};
	//but it does work for initialzing to a single value
	//pb a pointer to first element of pa
	auto pb = pa;
	//pre_c++ can use the following code instead
	//const double *(**pb)(const double *,int)= pa;
	cout << "\n using an array of pointers to function \n";
	cout << " Address value : ";
	for (int i=0;i<3;i++) {
		cout << pa[i](av,3) << ": "<< *pa[i](av,3)<<endl;         //函数指针
    }



	for (int i=0;i<3;i++) {
		cout << (*pb[i])(av,3)<< ": "<< *(*pb[i])(av,3)<<endl;   //函数
	}
	cout << "\n using a pointer to a pointer to a function \n";
	cout << "Address Value \n";  
	for (int i=0; i <3;i++) {                                    //函数指针，历史与逻辑   
		cout << pb[i](av,3)<< ": "<< *pb[i](av,3)<< endl;
	}
	 
	// what about a pointer to an array of function pointers
	cout << "\n using pointers to an array of pointer : \n";
	cout << "Address value : \n";
	//easy way to declare pc
	auto pc = &pa;
	cout << (*pc)[0](av,3) << ": " << *(*pc)[0](av,3) << endl;
	const double *(*(*pd)[3])(const double *,int) = &pa;
	//store return value in pdb
	const double * pdb = (*pd)[1](av,3);  //这是返回的double *
	cout << pdb << " : "<< *pdb << endl;
	//alternative notation 
	cout << (*(*pd)[2])(av,3)<< ": "<< *(*(*pd)[2])(av,3) << endl;
	cout << ((*pd)[2])(av,3)<< ": "<< *((*pd)[2])(av,3) << endl;
	system("pause");
	return 0;
}

const double * f1(const double * ar,int n)
{
	return ar;
}
const double * f2(const double ar[] ,int n)
{
	return ar+1;
}

const double *f3(const double ar[],int n)
{
	return ar+2;
}