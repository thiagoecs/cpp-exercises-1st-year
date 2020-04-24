#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class String {
	friend ostream& operator<<(ostream& out, const String& c);
public:
	String();
	String(const char* s1);
	String(const String& s2);
	const String& operator=(const String& s);
	String operator+(const String& s1) const;
	String& operator++();
	String operator++(int);
	char & operator[](int i) const;
	char& operator[](int i);
	operator const char* () const;
	static const int MAX_STRING_LENGTH = 10;
	~String();
	void list();
	static int getN();
private:
	char* c_string;
	static int n;
};

void display(const String& p);

int main(void) {
	String s("abcdefgsxxxxxxx"); // MAX_STRING_LENGTH is 10
	s[2] = 'Y';
	display(s); // outputs the string to the screen

	cout << String::getN() << endl;		// display the number of String objects
	{
		String array[4];
		cout << String::getN() << endl;		// display the number of String objects
	}
	cout << String::getN() << endl;		// display the number of String objects
	return 0;
}

String::String() {
	c_string = new char(0);
	n++;
}

int String::n = 0;

const String& String::operator=(const String& s) {
	if (this != &s) {
		delete[] c_string;
		c_string = new char[strlen(s.c_string) + 1];
		strcpy_s(c_string, strlen(s.c_string) + 1, s.c_string);
	}
	return *this;
}

String::String(const char* s1) {
	c_string = new char[strlen(s1) + 1];
	strncpy_s(c_string, MAX_STRING_LENGTH +1, s1, MAX_STRING_LENGTH);
	n++;
}

String::String(const String& s2) {
	c_string = new char[strlen(s2.c_string) + 1];
	strncpy_s(c_string, MAX_STRING_LENGTH +1, s2.c_string, MAX_STRING_LENGTH);
	n++;
}

String::~String() {
	//cout << "Destructor called" << endl;
	n--;
	delete[] c_string;
}

void String::list() {
	cout << c_string << endl;
}

ostream& operator<<(ostream& out, const String& c) {
	out << c.c_string << endl;
	return out;
}

 String String::operator+(const String& s1) const {
	String sum;
	delete sum.c_string;
	sum.c_string = new char[strlen(c_string) + strlen(s1.c_string) + 1];
	strcpy_s(sum.c_string, strlen(c_string) + strlen(s1.c_string) + 1, c_string);
	strcat_s(sum.c_string, strlen(c_string) + strlen(s1.c_string) + 1, s1.c_string);
	return sum;
}

String& String::operator++() {
	String sum;
	delete sum.c_string;
	sum.c_string = new char[strlen(c_string) + 2];
	strcpy_s(sum.c_string, strlen(c_string) + 2, c_string);
	strcat_s(sum.c_string, strlen(c_string) + 2, "X");
	swap(c_string, sum.c_string);
	return *this;
}

String String::operator++(int) {
	String sum(*this);
	delete sum.c_string;
	sum.c_string = new char[strlen(c_string) + 2];
	strcpy_s(sum.c_string, strlen(c_string) + 2, c_string);
	strcat_s(sum.c_string, strlen(c_string) + 2, "X");
	swap(c_string, sum.c_string);
	return sum;
}

char& String::operator[](int i) const {
	if (i > strlen(c_string)) {
		cout << "Array out of bounds" << endl;
		return c_string[0];
	}
	return c_string[i];
}

String::operator const char* () const {
	return c_string;
}

void display(const String& p) {
	for (int i = 0; i < String::MAX_STRING_LENGTH; i++) {
		cout << p[i];
	}
}

 char& String::operator[](int i)  {
	return c_string[i];
}

int String::getN()
{
	return n;
}
