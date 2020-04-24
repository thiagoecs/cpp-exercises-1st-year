#include <iostream>
#include <fstream>
#include <string>
#include "counter.h"

using namespace std;

class LimitedCounter : public Counter {
public:
	LimitedCounter(int count = 0, int lim = 0);
	LimitedCounter& operator++();
	LimitedCounter operator++(int);
	void setLimit(int const lim);
private:
	int limit;

};

int main() {
	LimitedCounter lc(3, 5); //initial value 3, upper limit 5
	cout << lc++ << endl; //output should be 3
	cout << ++lc << endl; //output should be 5
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

LimitedCounter::LimitedCounter(int lcount, int lim): Counter(lcount) {
	limit = lim;
}

LimitedCounter& LimitedCounter::operator++() {
	if (Counter::getCount() < limit)
		Counter::operator++();
	return *this;
}

LimitedCounter LimitedCounter::operator++(int) {
	LimitedCounter old(*this);
	if (getCount() < limit)
		Counter::operator++();
	return old;
}


void LimitedCounter::setLimit(int const lim) {
	limit = lim;
}


ostream& operator<<(ostream& out, const LimitedCounter& c) {
	out << c.getCount() << endl;
	return out;
}
