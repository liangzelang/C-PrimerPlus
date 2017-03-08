#ifndef TEBTEN_H_
#define TEBTEN_H_

#include <string>
using std::string;

class TableTennisPlayer
{
private:
	string firstname;
	string lastname;
	bool hasTable;
public:
	TableTennisPlayer(const string & fn = "none", const string & ln = "none", bool ht = false);
	~TableTennisPlayer();
	void Name() const;  //���ı������
	bool HasTable() const { return hasTable; };
	void ResetTable(bool v) { hasTable = v; };

};

class RatePlayer : public TableTennisPlayer
{
private:
	unsigned int rating;
public:
	RatePlayer(unsigned int r = 0, const string & fn = "none", const string & ln = "none", bool ht = false);
	//RatePlayer(unsigned int r = 0, const TableTennisPlayer & tp);  //����д����һ��������ǣ�Ĭ�ϲ�������������
	RatePlayer(unsigned int r, const TableTennisPlayer & tp);
	unsigned int Rating() const {return rating; };
	void ResetRating(unsigned int r) { rating = r;};
}; 

#endif