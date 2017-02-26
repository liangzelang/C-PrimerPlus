#ifndef TIME_H_
#define TIME_H_
class Time
{
private:
	int m_hours;
	int m_minutes;
public:
	Time();
	Time(int hours, int minutes = 0);
	void AddHr(int hours);
	void AddMin(int minutes);
	void Reset(int hours=0, int minutes=0);
	Time Sum(const Time & t) const;
	Time operator+(const Time & t) const;
	void Show() const;
};   //不要老是忘掉这个符号

#endif