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
#endif