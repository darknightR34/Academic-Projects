#include <iostream>;
using namespace std;

void fillArray(int array[], int size);
void printArray(double array[], int size);
void printArray(int array[], int size);
void sortArray(int array[], int size, bool choice);
void swap(int& num1, int& num2);

int main()
{
	const int MAX = 10;
	int userInput, array[MAX];
	char userChoice = 'y', sortOrder;

	while (userChoice != 'n') {
		cout << " How many elements in your array [up to 10]: ";
		cin >> userInput;

		fillArray(array, userInput);
		printArray(array, userInput);

		cout << " Sort in [i]ncreasing or [d]ecreasing? ";
		cin >> sortOrder;

		if (sortOrder == 'i') {
			sortArray(array, userInput, 1);
		}
		else if (sortOrder == 'd') {
			sortArray(array, userInput, 0);
		}
		
		cout << " Would you like to run the program again (y/n)? ";
		cin >> userChoice;
	}

	cout << " Thank you for using the program! Goodbye!";
	return 0;
}

void fillArray(int array[], int size) {
	cout << " Enter " << size << " integers separated by spaces: \n ";
	for (int i = 0; i < size; i++) {
		cin >> array[i];
	}
}

void printArray(double array[], int size) {
	cout << " You entered the array: \n ";
	for (int i = 0; i < size; i++) {
		cout << array[i] << ' ';
	}
	cout << endl;
}

void printArray(int array[], int size) {
	cout << " You entered the array: \n ";
	for (int i = 0; i < size; i++) {
		cout << array[i] << ' ';
	}
	cout << endl;
}

void sortArray(int array[], int size, bool choice) {
	int count = 0;

	if (choice == 1) {
		for (int i = 0; i < size; i++) {
			for (int j = (i + 1); j < size; j++) {
				if (array[j] < array[i]) {
					count++;
					swap(array[j], array[i]);
					
					for (int k = 0; k < size; k++) {
						cout << ' ' << array[k];
					}
					cout << endl;
				}
			}
		}
		cout << " Our array was sorted in " << count << " swaps\n";
	}
	else if (choice == 0) {
		for (int i = 0; i < size; i++) {
			for (int j = (i + 1); j < size; j++) {
				if (array[j] > array[i]) {
					count++;
					swap(array[j], array[i]);

					for (int k = 0; k < size; k++) {
						cout << ' ' << array[k];
					}
					cout << endl;
				}
			}
		}
		cout << " Our array was sorted in " << count << " swaps\n";
	}
}

void swap(int& num1, int& num2) {
	int temp = num1;
	num1 = num2;
	num2 = temp;
}