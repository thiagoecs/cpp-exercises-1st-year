#include <iostream>
using namespace std;

class String {
	friend ostream& operator<<(ostream& out, const String& s);
public:
	String();
	String(const char* s1);
	String(const String& s2);
	~String();
	const String &operator =(const String& s);
	String operator+(const String& s);
	String& operator++();
	String operator++(int);
	char& operator[](int i);
	void list();
private:

	char* c_string;
};

void f(String s);

int main() {
	String s("abcdefg");
	for (int i = 0; i < 7; i++)
		cout << s[i] << " ";
	s[4] = 'X';
	for (int i = 0; i < 7; i++)
		cout << s[i] << " ";
	return 0;
}
/*int main() {
	String s("abcdefg");
	cout << s++ << endl;
	cout << ++s << endl;
	return 0;
}
*/
/*
int main() {
	String s1("abcedf");
	String s2("ghijklmn");
	String sum;
	cout << "String 1 is:" << s1 << endl;
	cout << "String 2 is:" << s2 << endl;
	sum = s1 + s2;
	cout << "Sum is :" << sum; // output should be
	// abcdefghijklmn
	// This should also work
	sum = sum;
	cout << "Sum is still :" << sum; // output should
	// still be abcdefghijklmn
	return 0;
}*/

String::String()
{
	c_string = new char(0);
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


const String& String::operator=(const String& s)
{
	if (this != &s) {
		delete c_string;
		c_string = new char[strlen(s.c_string) + 1];
		strcpy_s(c_string, strlen(s.c_string) + 1, s.c_string);
	}
	return *this;
}

String String::operator+(const String& s)
{
	String sum;
	delete sum.c_string;

	sum.c_string = new char[strlen(c_string) + strlen(s.c_string) + 1];
	strcpy_s(sum.c_string, strlen(c_string) + strlen(s.c_string) + 1, c_string);
	strcat_s(sum.c_string, strlen(c_string) + strlen(s.c_string) + 1, s.c_string);
	return sum;
}

String& String::operator++()
{
	String sum;
	delete sum.c_string;
	
	sum.c_string = new char[strlen(c_string) + 2];
	strcpy_s(sum.c_string, strlen(c_string)+ 2, c_string);
	strcat_s(sum.c_string, strlen(c_string)+2, "X");
	swap(c_string, sum.c_string);
	return *this;
	
}

String String::operator++(int)
{
	String sum(*this);
	delete sum.c_string;

	sum.c_string = new char[strlen(c_string) + 2];
	strcpy_s(sum.c_string, strlen(c_string) + 2, c_string);
	strcat_s(sum.c_string, strlen(c_string) + 2, "X");
	swap(c_string, sum.c_string);
	return sum;
}

char& String::operator[](int i)
{
	if (i > strlen(c_string)) {
		cout << "Array out of bounds" << endl;
		return c_string[0];
	}
	return c_string[i];
}

ostream& operator<<(ostream& out, const String& s)
{
	out << s.c_string << endl;
	return out;
}



