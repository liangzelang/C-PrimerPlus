#ifndef STRINGUSER_H_
#define STRINGUSER_H_

#include <iostream>

class StringUser
{
private:
	char *str;
	int len;
	static int num_strings;
public:
	StringUser(const char *s);
	StringUser(const StringUser &);
	StringUser();
	~StringUser();

	StringUser & operator=(const StringUser &);

	friend std::ostream & operator<<(std::ostream & os, const StringUser & st);
};

#endif
