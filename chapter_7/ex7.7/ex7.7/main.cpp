////////////////////////////////////////////////////////////////////
//                          _ooOoo_                               //
//                         o8888888o                              //
//                         88" . "88                              //
//                         (| ^_^ |)                              //
//                         O\  =  /O                              //
//                      ____/`---'\____                           //
//                    .'  \\|     |//  `.                         //
//                   /  \\|||  :  |||//  \                        //
//                  /  _||||| -:- |||||-  \                       //
//                  |   | \\\  -  /// |   |                       //
//                  | \_|  ''\---/''  |   |                       //
//                  \  .-\__  `-`  ___/-. /                       //
//                ___`. .'  /--.--\  `. . ___                     //
//              ."" '<  `.___\_<|>_/___.'  >'"".                  //
//            | | :  `- \`.;`\ _ /`;.`/ - ` : | |                 //
//            \  \ `-.   \_ __\ /__ _/   .-` /  /                 //
//      ========`-.____`-.___\_____/___.-`____.-'========         //
//                           `=---='                              //
//      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^        //
//         佛祖保佑       永无BUG     永不修改                    //
////////////////////////////////////////////////////////////////////
// arrfun2.cpp -- array functions and const
// 作者： liangzelang@gmail.com
// 时间： 2017/02.26

#include <iostream>
const int Max = 5;

//function prototypes
double* fill_array(double * header, double * last);
void show_array(const double* header,const double* last);
void revalue( double r, double* header, double* last );

int main()
{
	using namespace std;
	double properties[Max];
	double* end = fill_array(properties, properties+Max);
	show_array(properties, end);
	if(end > properties)
	{
		cout << "Enter revaluation factor: ";
		double factor;

		while( !(cin>>factor))
		{
			cin.clear();
			while(cin.get() != '\n')
				continue;
			cout << "Bad input; please enter a number: ";
		}
		revalue(factor, properties, end);
		show_array(properties, end);
	}

	cout << "Done. \n";
	cin.get();  //为什么会有两个连续的get（）？？？
	cin.get();
	return 0;
}

double* fill_array(double * header, double * last)
{
	using namespace std;
	double temp;
	int i = 1;
	while( header < last)
	{
		cout << "Enter Properties #" << i << ": "<< endl;
		cin >>temp;
		if(!cin)
		{
			cin.clear();
			while(cin.get() != '\n')
				continue;
			cout << "Bad input , input process terminated. \n ";
			break;
		}
		if(temp < 0)
			break;
		*header = temp;
		header++;
		i++;
	}
	return header;
}
void show_array(const double* header,const double* last)
{
	using namespace std;
	int i = 1;
	while( header < last)
	{
		cout << "Properties #" << i << ": " << *header << endl;
		header++;
		i++;
	}

}
void revalue( double r, double* header, double* last )
{
	while(header < last)
	{
		*header *= r;
		header++;
	}
}
