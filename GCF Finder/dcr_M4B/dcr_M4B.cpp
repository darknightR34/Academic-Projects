#include <iostream>;

using namespace std;

void GCF(int num1, int num2);

int main()
{
	char userChoice = 'y';
	int value1, value2;

	while (userChoice != 'n') {
		cout << " Enter two integers, separated by a space: ";
		cin >> value1 >> value2;

		GCF(value1, value2);

		cout << " Would you like to find another GCF? (y/n) ";
		cin >> userChoice;
	}

	cout << " Thank you for using the program, goodbye!";

	return 0;
}

void GCF(int num1, int num2) {
	
	int lowestVal, highestVal, compare1, compare2;

	if (num1 >= num2) {
		highestVal = num1;
		lowestVal = num2;
	}
	else {
		highestVal = num2;
		lowestVal = num1;
	}

	for (int i = lowestVal; i > 0; i--) {
		compare1 = lowestVal % i;
		compare2 = highestVal % i;

		if (compare1 == compare2 && compare1 == 0) {
			cout << " GCF of " << num1 << " and " << num2 << " is " << i << endl;
			break;
		}
	}
}