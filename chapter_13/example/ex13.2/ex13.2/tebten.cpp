#include "tebten.h"
#include <iostream>
using namespace std;

//�������ַ���Ҳ����
/*TableTennisPlayer::TableTennisPlayer(const string & fn , const string & ln , bool ht)
{
	firstname = fn;
	lastname = ln;
	hasTable = ht;
}*/

// ��Ա���»��б� �Ƽ�ʹ��
TableTennisPlayer::TableTennisPlayer(const string & fn, const string & ln, bool ht) : firstname(fn), lastname(ln), hasTable(ht)
{
	
}

TableTennisPlayer::~TableTennisPlayer()
{
	
}

void TableTennisPlayer::Name() const  //���ı������
{
	std::cout << lastname << ", " << firstname << endl;
}

//RatePlayer methods
RatePlayer::RatePlayer(unsigned int r, const string & fn, const string & ln, bool ht) : rating(r), TableTennisPlayer(fn, ln, ht)
{

}

RatePlayer::RatePlayer(unsigned int r, const TableTennisPlayer & tp): rating(r),TableTennisPlayer(tp)  //�����Զ�����һ�����ƹ��캯��
{

}