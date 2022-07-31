#include <iostream>
using namespace std;

int* getPositives(int arr[], int size);
void printArray(int arr[], int size);
void printArray(int* p);

int main()
{
	int ain[] = { -23, 55, 7, 2, 9, 0, -88, -10, 1, 3 };

	cout << " Input array: " << endl;
	printArray(ain, 10);

	cout << endl;
	int* aout = getPositives(ain, 10);
	cout << " Positive numbers: " << endl;
	printArray(aout);

	delete[] aout, aout = nullptr;
	cout << endl;

	return 0;
}

int* getPositives(int arr[], int size) {
	int* a1 = new int[size];
	int count = 0;

	for (int i = 0; i < size; i++) {
		if (arr[i] >= 0) {
			a1[count] = arr[i];
			count++;
		}
		else { continue; }
	}
	a1[count] = -1;

	return a1;
}

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << ' ' << arr[i];
	}
}

void printArray(int* p) {
	int count = 0;
	while (*(p+count) != -1) {
		cout << ' ' << *(p+count);
		count++;
	}
}