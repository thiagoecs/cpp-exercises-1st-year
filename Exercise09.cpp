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
private:
	int limit;

};

class RoundupCounter : public Counter {
public:
	RoundupCounter(int count = 0, int lim = 0);
	RoundupCounter& operator++();
	RoundupCounter operator++(int);
private:
	int limit;
};
void UseCounter(Counter* counter, int inc);

int main() {
	LimitedCounter counterA(0, 5);
	RoundupCounter counterB(0, 5);
	UseCounter(&counterA, 8); UseCounter(&counterB, 8);
	cout << "Counter A: " << counterA << endl; // output should be 5
	cout << "Counter B: " << counterB << endl; // output should be 2
	return 0;
}


LimitedCounter::LimitedCounter(int lcount, int lim) : Counter(lcount) {
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

RoundupCounter::RoundupCounter(int lcount, int lim) : Counter(lcount) {
	limit = lim;
}

RoundupCounter& RoundupCounter::operator++(){
	if (getCount() < limit)
		Counter::operator++();
	else reset();
	return *this;
}

RoundupCounter RoundupCounter::operator++(int){
	RoundupCounter old(*this);
	if (getCount() < limit)
		Counter::operator++();
		return old;
}


void UseCounter(Counter* counter, int inc){
	for (int i = 0; i < inc; i++) {
		counter->operator++();
	}
}
