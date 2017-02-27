#include <iostream>
#include <string>
using namespace std;
const int SLEN = 30;
struct student{
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

int getinfo( student pa[] , int n );
void display1(student st);
void display2(const student * ps);
void display3(const student pa[], int n);

int main()
{
	cout << "Enter class size: ";
	int class_size;
	cin >> class_size;
	while(cin.get() != '\n')
		continue;
	student * ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	for(int i = 0; i < entered; i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);
	delete [] ptr_stu;
	cout << "Done.\n" << endl;
	system("pause");
	return 0;
}

int getinfo( student pa[] , int n )
{
	int i;
	char temp[SLEN];
	cout << "Please input students' info. \n" << endl;
	for(i = 0; i < n; i ++)
	{
		cout << "\nPlease input Student " << i+1 << " Fullname (quit to quit): ";
		cin >> temp;
		cout << temp;
		if( temp == "quit") break;     //这种方法明显是错误的
		if(!strcmp(temp, "quit")) break; //OK 
		//pa[i].fullname = temp;  //char数组不能直接赋值
		strcpy(pa[i].fullname, temp);
		cout << "\n" << "Student " << i + 1 << " hobby : ";
		cin >> pa[i].hobby;
		cout << "\n" << "Student " << i + 1 << " ooplevel : ";
		cin >> pa[i].ooplevel;
		
	}
	return i;
}
void display1(student st)
{
	cout << "Student :\nName: " << st.fullname << "  Hobby: " << st.hobby << "  OOPLevel: " << st.ooplevel << "\n" << endl; 
}
void display2(const student * ps)
{
	cout << "Student :\nName: " << ps->fullname << "  Hobby: " << ps->hobby << "  OOPLevel: " << ps->ooplevel << "\n" << endl;
}
void display3(const student pa[], int n)
{
	for(int i = 0; i < n; i++)
	{
		display1(pa[i]);
	}
}