#include <iostream>
#include "time.h"

Time::Time()
{
	m_hours = 0;
	m_minutes = 0;
}

Time::Time(int hours, int minutes)
{
	m_hours = hours;
	m_minutes = minutes;
}

void Time::AddHr(int hours)
{
	m_hours += hours;
}

void Time::AddMin(int minutes)
{
	if(m_minutes + minutes >= 60) {
		m_minutes = m_minutes + minutes - 60;
		m_hours += 1;
	}
	else
		m_minutes += minutes;
}

void Time::Reset(int hours, int minutes)
{
	m_hours = hours;
	m_minutes = minutes;
}

Time Time::Sum(const Time & t) const
{
	Time sum;
	if(m_minutes + t.m_minutes >= 60) {
		sum.m_minutes = m_minutes + t.m_minutes -60;
		sum.m_hours = m_hours + t.m_hours +1;
	} else {
		sum.m_minutes = m_minutes + t.m_minutes;
		sum.m_hours = m_hours + t.m_hours;
	}
	return sum;
}

Time Time::operator+(const Time & t) const
{
	Time sum;
	if(m_minutes + t.m_minutes >= 60) {
		sum.m_minutes = m_minutes + t.m_minutes -60;
		sum.m_hours = m_hours + t.m_hours +1;
	} else {
		sum.m_minutes = m_minutes + t.m_minutes;
		sum.m_hours = m_hours + t.m_hours;
	}
	return sum;
}

Time operator*(double n , const Time & t) 
{
	Time sum;
	long totalminutes = t.m_hours * 60 * n + t.m_minutes * n;
	sum.m_hours = totalminutes / 60;
	sum.m_minutes = totalminutes % 60;
	return sum;
}
/*
void operator<<(std::ostream & os, const Time & t)
{
	os << t.m_hours << " hours , " << t.m_minutes << "minutes.\n";
}*/

std::ostream & operator<<(std::ostream & os, const Time & t)
{
	os << t.m_hours <<" hours, " << t.m_minutes << " minutes .\n";
	return os;
}
void Time::Show() const
{
	std::cout << "The Traval	Time is : "<< m_hours << " hours, " << m_minutes << " minutes .\n";
}