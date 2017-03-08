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
	void Name() const;  //不改变这个类
	bool HasTable() const { return hasTable; };
	void ResetTable(bool v) { hasTable = v; };

};

class RatePlayer : public TableTennisPlayer
{
private:
	unsigned int rating;
public:
	RatePlayer(unsigned int r = 0, const string & fn = "none", const string & ln = "none", bool ht = false);
	//RatePlayer(unsigned int r = 0, const TableTennisPlayer & tp);  //这样写犯了一个错误就是，默认参数必须放在最后
	RatePlayer(unsigned int r, const TableTennisPlayer & tp);
	unsigned int Rating() const {return rating; };
	void ResetRating(unsigned int r) { rating = r;};
}; 

#endif