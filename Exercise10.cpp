#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <iomanip>
#include <vector>
#include <iterator>

using namespace std;

int main() {

	/*
	pair<int, pair<string, string>> pair1(123, make_pair("aaaaa", "xxxxxxx")), pair2(345, make_pair("bbb", "yyy"));

	cout << "no\tfirst name\tlastname" << endl;
	cout << pair1.first << "\t" << setw(10) << left << pair1.second.first << "\t" << pair1.second.second << endl;
	cout << pair2.first << "\t" << setw(10) << left << pair2.second.first << "\t" << pair2.second.second << endl;*/

	vector<string> strings;
	string input, longest = "";
	cout << "Enter text. Enter \"stop\" to end program" << endl;
	while (getline(cin, input) && input != "stop") {
		strings.push_back(input);
		if (input.size() > longest.size())
			longest = input;
	}

	cout << "Longest word was \"" << longest << "\"" << endl;
	cout << "List of all words entered:" << endl;

	copy(strings.begin(), strings.end(), ostream_iterator<string>(cout, "\n"));

	cout << "Number of words entered: " << strings.size() << endl;
	cout << "Size: " << strings.size() << "\t Capacity: " << strings.capacity() << "\t Sizeof: " << sizeof(strings) << endl;

	//size - the number of elements that the vector contains
	//capacity - is the amount of space the vector is currently using
	//sizeof - returns the size of the vector object
	
}