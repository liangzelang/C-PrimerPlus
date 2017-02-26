#ifndef STRING1_H_
#define STRING1_H_

#include <iostream>

class StringUser
{
private:
	char *str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;
public:
	//constructors and other methods
	StringUser(const char *s);
	StringUser(const StringUser &);
	StringUser();
	~StringUser();
	int length() const  {return len;}


	//overloaded operator methods
	StringUser & operator=(const StringUser &);
	StringUser & operator=(const char *);
	char & operator[](int i);
	const char &operator[](int i) const ;

	//overloaded operator friends
	friend bool operator<(const StringUser &st, const StringUser &st2);
	friend bool operator>(const StringUser &st, const StringUser &st2);
	friend bool operator==(const StringUser &st, const StringUser &st2);

	friend std::ostream & operator<<(std::ostream & os, const StringUser & st);
	friend std::istream & operator>>(std::istream & os, StringUser &st);

	//static functon
	static int HowMany();
};

#endif
