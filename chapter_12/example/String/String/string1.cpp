#include <cstring>
#include "string1.h"
using std::cout;
using std::cin;

// initialize static class member
int StringUser::num_strings = 0;

// static method
int StringUser::HowMany()
{
	return num_strings;
}


// class methods
// constructors
StringUser::StringUser(const char * s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str,s);
	num_strings++;
	//cout << num_strings << ":\"" << str << "\" object created \n";
}

StringUser::StringUser(const StringUser & temp)
{
	num_strings++;
	len = temp.len;
	str = new char [len + 1];
	std::strcpy(str,temp.str);
	//cout << num_strings << " :\" " << str << " \" objected created \n";

}
StringUser::StringUser()
{
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
	//cout << num_strings << ": \"" << str <<" \" default object created \n";
}

StringUser::~StringUser()
{
	//cout << "\"" << str << " \" object deleted, ";
	--num_strings;
	//cout << num_strings << " lefts \n";
	delete [] str;
}


//overloaded operator methods
	
	//assign a StringUser to a StringUser
StringUser & StringUser::operator=(const StringUser & st)
{
	if(this == &st)
		return *this;
	delete [] str;
	len = st.len;
	str = new char [len + 1];
	std::strcpy(str, st.str);
	return *this;
}
	
	//assign a C string to a StringUser

StringUser & StringUser::operator=(const char * s)
{
	delete [] str;
	len = std::strlen(s);
	str = new char [len + 1];
	std::strcpy(str, s);
	return *this;
}

	// read-write char access for non-const StringUser
char & StringUser::operator[](int i)
{
	return str[i];
}
	// read-only char access for const StringUser
const char & StringUser::operator[](int i) const
{
	return str[i];
}

//overloaded operator friends

	//
bool operator<(const StringUser &st1, const StringUser &st2)
{
	return (std::strcmp(st1.str,st2.str) < 0);
}

bool operator>(const StringUser &st1, const StringUser &st2)
{
	return st2 < st1;
}

bool operator==(const StringUser &st1, const StringUser &st2)
{
	return (std::strcmp(st1.str,st2.str)==0);
}
	//simple StringUser output
std::ostream & operator<<( std::ostream & os , const StringUser & st)
{
	os << st.str ;
	return os;
}
	//simple StringUser input

std::istream & operator>>(std::istream & is,  StringUser &st)
{
	char temp[StringUser::CINLIM];
	is.get(temp,StringUser::CINLIM);
	if(is)
	{
		st = temp;  //调用重载的=运算符，把c字符串赋值给class StringUser
	}
	while(is && is.get()!='\n')
		continue;
	return is;
}