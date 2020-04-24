#include <iostream>
using namespace std;

class String {
public:
	String(const char* s1);
	void list();
private:
	char c_string[11];
};

void f(String s);

void main() {
	String s("abcdefg");
	s.list();
	f(s);
	s.list();
}

String::String(const char* s1)
{
	strcpy_s(c_string, 11, s1);
}

void String::list()
{
	cout << c_string << endl;
}

void f(String s)
{
	s.list();
}
