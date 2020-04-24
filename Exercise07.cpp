#include <iostream>
#include <fstream>
#include <string>
#include "counter.h"

using namespace std;

class LimitedCounter {
	friend ostream& operator<<(ostream& out, const LimitedCounter& c);
public:
	LimitedCounter(int count = 0, int lim = 0);
	LimitedCounter& operator++();
	LimitedCounter operator++(int);
	bool operator<(const int c2) const;
	void reset();
	void setLimit(int const lim);
	int getCount();
private:
	Counter counter;
	int limit;
};

int main() {
	LimitedCounter lc(0, 5); //initial value 0, upper limit 5
	cout << lc++ << endl; //output should be 0
	cout << ++lc << endl; //output should be 2
	lc.reset();
	for (int i = 0; i < 9; i++) {
		lc++;
		cout << lc << endl; //output is 1 2 3 4 5 5 5 5 5
	}
	cout << lc.getCount() << endl; //output is 5
	cout << (lc < 7);//Testing the comparison operator //output is 1
	cout << (lc < 1);//Testing the comparison operator //output is 0
	return 0;
}

LimitedCounter::LimitedCounter(int lcount, int lim) : counter(lcount) {
	limit = lim;
}

LimitedCounter& LimitedCounter::operator++() {
	if (counter.getCount() < limit)
		++counter;
	return *this;
}

LimitedCounter LimitedCounter::operator++(int){
	LimitedCounter old(*this);
	if (counter.getCount() < limit)
		++counter;
	return old;
}

bool LimitedCounter::operator<(const int c2) const
{
	return counter.getCount() < c2;
}

void LimitedCounter::reset(){
	counter.reset();
}

void LimitedCounter::setLimit(int const lim) {
	limit = lim;
}

int LimitedCounter::getCount() {
	return counter.getCount();
}

ostream& operator<<(ostream& out, const LimitedCounter& c) {
	out << c.counter.getCount() << endl;
	return out;
}
