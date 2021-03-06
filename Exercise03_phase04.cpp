#include <iostream>
using namespace std;

class String {
public:
	String(const char* s1);
	String(const String& s2);
	~String();
	void list();
private:

	char* c_string;
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
	c_string = new char[strlen(s1) + 1];
	strcpy_s(c_string, strlen(s1) + 1, s1);
}

void String::list()
{
	cout << c_string << endl;
}

void f(String s)
{
	s.list();
}

String::~String()
{
	cout << "destructor done" << endl;
	delete c_string;

}

String::String(const String& s2)
{
	c_string = new char[strlen(s2.c_string) + 1];
	strcpy_s(c_string, strlen(s2.c_string) + 1, s2.c_string);
}
