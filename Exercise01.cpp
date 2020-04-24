#include <iostream>
#include <cstdlib>
using namespace std;

float mean(int* array, int n);

int main() {
	int input;
	int* numbers;

	cout << "Enter how many numbers: " << endl;
	cin >> input;
	numbers = new int[input];

	for (int i = 0; i < input; i++) {
		numbers[i] = rand() % 100;
		cout << numbers[i] << endl;
	}
	cout << "The average numbers is " << mean(numbers, input) << endl;

	delete[] numbers;
	cin.get();
}

	float mean(int* array, int n) {

		float sum = 0;

		for (int i = 0; i < n; i++) {
			sum += array[i];
		}
		sum /= n;

		return sum;
	}


