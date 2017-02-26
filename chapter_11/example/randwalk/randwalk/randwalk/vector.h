#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>

class Vector
{
public :
	enum Mode {Rect,Pol};
private :
	double x;
	double y;
	double mag;
	double angle;
	Mode mode;
	void set_mag();
	void set_ang();
	void set_x();
	void set_y();
public:
	Vector();
	Vector(double n1,double n2,Mode form = Rect);
	void Reset(double n1, double n2, Mode form = Rect);
	~Vector();
	double x_val() const { return x;}
	double y_val() const { return y;}
	double mag_val() const { return mag;}
	double ang_val() const { return angle;}
	void polar_mode();
	void rect_mode();
	//Overload
	Vector operator+(const Vector & t) const;
	Vector operator-(const Vector & t) const;
	Vector operator-() const;
	Vector operator*(double n) const;

	//friend
	friend Vector operator*(double n, const Vector & t);
	friend std::ostream & operator<<(std::ostream & os ,const Vector & t);
};




#endif