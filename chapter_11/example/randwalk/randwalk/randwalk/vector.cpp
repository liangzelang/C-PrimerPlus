#include <cmath>
#include <iostream>
#include "vector.h"

using namespace std;

void Vector::set_mag()
{
	mag = sqrt(x*x+y*y);
}

void Vector::set_ang()
{
	if((x == 0)&&(y == 0))
		angle = 0;
	else 
		angle = atan2(y,x);
}

void Vector::set_x()
{
	x = mag * cos(angle);
}

void Vector::set_y()
{
	y = mag * sin(angle);
}


Vector::Vector()
{
	x = y = 0;
	mag = angle = 0;
	mode = Rect;
}

Vector::Vector(double n1, double n2, Mode form)
{
	mode = form;
	if( mode == Rect) {
		x = n1;
		y = n2;
		set_mag();
		set_ang();
	} else if( mode == Pol) {
		mag = n1;
		angle = n2 / 57.3;
		set_x();
		set_y();
	} else {
		cout << "Please choose the right mode.\n";
		x = y = mag = angle =0;
		mode = Rect;
	}
}

Vector::~Vector()
{
	// TO DO
}
void Vector::Reset(double n1, double n2, Mode form)
{
	mode = form;
	if( mode == Rect) {
		x = n1;
		y = n2;
		set_mag();
		set_ang();
	} else if( mode == Pol) {
		mag = n1;
		angle = n2/57.3;
		set_x();
		set_y();
	} else {
		cout << "It is wrong";
		x = y = mag = angle = 0;
		mode = Rect;
	}
}

void Vector::polar_mode()
{
	mode = Pol;
}

void Vector::rect_mode()
{
	mode = Rect;
}

Vector Vector::operator+(const Vector & t) const
{
	return Vector(x + t.x, y + t.y);
}
Vector Vector::operator-(const Vector & t) const
{
	return Vector(x - t.x, y- t.y);
}

Vector Vector::operator-() const
{
	return Vector(-x,-y);
}

Vector Vector::operator*(double n) const
{
	return Vector(x*n,y*n);
}

Vector operator*(double n, const Vector & t)
{
	return t*n;
}

std::ostream & operator<<(std::ostream & os ,const Vector & t)
{
	if(t.mode == Vector::Rect)
	{
		os << "(x,y) = (" << t.x << ", " << t.y << "). \n";  	
	} else if(t.mode == Vector::Pol) {
		os << "(mag,angle) = (" << t.mag << ", " << t.angle*57.3 << ") .\n";
	} else
		os << "Vector object mode is invalid";
	return os;
}


