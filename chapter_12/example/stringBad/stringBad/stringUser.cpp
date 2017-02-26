#include <cstring>
#include "stringUser.h"
using std::cout;
int StringUser::num_strings = 0;

StringUser::StringUser(const char * s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str,s);
	num_strings++;
	cout << num_strings << ":\"" << str << "\" object created \n";
}

StringUser::StringUser(const StringUser & temp)
{
	num_strings++;
	len = temp.len;
	str = new char [len + 1];
	std::strcpy(str,temp.str);
	cout << num_strings << " :\" " << str << " \" objected created \n";

}
StringUser::StringUser()
{
	len = 4;
	str = new char[4];
	std::strcpy(str,"C++");
	num_strings++;
	cout << num_strings << ": \"" << str <<" \" default object created \n";
}

StringUser::~StringUser()
{
	cout << "\"" << str << " \" object deleted, ";
	--num_strings;
	cout << num_strings << " lefts \n";
	delete [] str;
}

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
std::ostream & operator<<( std::ostream & os , const StringUser & st)
{
	os << st.str ;
	return os;
}