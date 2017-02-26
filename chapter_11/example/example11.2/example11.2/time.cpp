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

void Time::Show() const
{
	std::cout << "The Traval	Time is : "<< m_hours << " hours, " << m_minutes << " minutes .\n";
}