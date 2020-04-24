#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Counter {
public:
	void reset();
	void increment();
	int getCount();
private:
	int count;
};

class Dice {
public:
	void initialize();
	float roll();
};

class Inspector {
public:
	bool isInLimits(float number);
	void setLimits(float l_limit, float u_limit);
private:
	float lower_limit, upper_limit;
};

int main() {
	Dice dice;
	Counter counter1, counter2, i;
	Inspector inspector;
	dice.initialize();
	counter1.reset(); counter2.reset(), i.reset();
	inspector.setLimits(0.0, 0.5);
	while (i.getCount() < 100) {
		if (inspector.isInLimits(dice.roll()))
			counter1.increment();
		else
			counter2.increment();
		i.increment();
	}
	cout << counter1.getCount() << endl;
	cout << counter2.getCount() << endl;
	return 0;
}

void Counter::reset() {
	count = 0;
}

void Counter::increment() {
	count++;
}

int Counter::getCount() {
	return count;
}

void Dice::initialize() {
	srand(time(NULL));
}

float Dice::roll() {
	return (float)rand() / RAND_MAX;
}

bool Inspector::isInLimits(float number) {
	if (number >= lower_limit && number <= upper_limit)
		return true;
	else
		return false;
}

void Inspector::setLimits(float l_limit, float u_limit) {
	lower_limit = l_limit;
	upper_limit = u_limit;
}