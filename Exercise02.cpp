#include <iostream>
using namespace std;

class Time {
public:

	void read(const char *number);
	bool lessThan(Time t);
	Time subtract(Time x);
	void display();
private:
	int hour;
	int min;
	
};

int main() { 
	Time time1, time2, duration;
	time1.read("Enter time 1");
	time2.read("Enter time 2");
	if (time1.lessThan(time2))
	{ 
		duration = time2.subtract(time1);
		cout << "Starting time was ";
		time1.display();
	}
	else 
	{ 
		duration = time1.subtract(time2);
		cout << "Starting time was ";
		time2.display();
	}
	cout << "Duration was ";
	duration.display();
	return 0; 
}

void Time::read(const char *number) {
	char colon;
	cout << number << endl;
	cin >> hour >> colon >> min;
}

bool Time::lessThan(Time t) {
	if (hour < t.hour || (hour == t.hour && min < t.min)) {
		return true;
	}
	else
		return false;
	
	
}

Time Time::subtract(Time x){
	Time aux;
	int auxmin;
	auxmin = (hour * 60 + min) - (x.hour * 60 + x.min);
	aux.hour = auxmin / 60;
	aux.min = auxmin % 60;
	return aux;
}

void Time::display() {
	cout << hour << ':' << min << endl;


}

