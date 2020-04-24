#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iomanip>

using namespace std;

class RandGen_2 { 
public: 
	RandGen_2() : numbers() { srand(time(NULL));} 
int operator()();
private: 
	vector<int> numbers; 
};

void main(void) {
	vector<int> numbers(7), numbers2(7), same;	//this is how to use "ordinary"function 
	/* srand(time(NULL)); // it is necessary to remember to call this 
	generate(numbers.begin(), numbers.end(), randGen_1); */ 
	//this is how to use function object 
	RandGen_2 randGen_1; 
	generate(numbers.begin(), numbers.end(), randGen_1); 
	generate(numbers2.begin(), numbers2.end(), randGen_1);
	/*for (unsigned int i = 0 ; i < numbers.size(); i++) 
		cout << numbers[i]<< endl; */ 
	ostream_iterator<int> out_it(cout, " ");
	cout << "First lotto row: ";
	copy(numbers.begin(), numbers.end(), out_it); 
	cout << endl;
	cout << "Second lotto row: ";
	copy(numbers2.begin(), numbers2.end(), out_it);
	cout << endl;

	sort(numbers.begin(), numbers.end());
	sort(numbers2.begin(), numbers2.end());
	set_intersection(numbers.begin(), numbers.end(), numbers2.begin(), numbers2.end(), back_inserter(same));
	if (same.size() != 0) {
		int i = 1;
		cout << "Same numbers: " << endl;
		for_each(same.begin(), same.end(), [&i](int num) { cout << "#" << i << ": " << num << endl; i++;});
	}
}

int RandGen_2::operator()() { 
	int number; 
	do { 
		number = rand() % 37 + 1; 
	} while (find(numbers.begin(), numbers.end(), number) != numbers.end()); 
	numbers.push_back(number); 
	return number; 
}
