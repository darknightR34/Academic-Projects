#include <iostream>;

using namespace std;

int isFriday(int month, int day, int year);

int main()
{
	int month, day, year;
	char userChoice = 'y';

	while (userChoice != 'n') {
		cout << " Enter the month: ";
		cin >> month;

		cout << " Enter the day: ";
		cin >> day;

		cout << " Enter the year (last 2 digits): ";
		cin >> year;

		int result = isFriday(month, day, year);
		if (result == 1) {
			cout << " It's Friday!!! Wooo!" << endl;
		}
		else {
			cout << " It's not Friday yet :(" << endl;
		}

		cout << " Would you like to run the program again (y/n)? ";
		cin >> userChoice;
	}
	cout << " Thank you for using the program, goodbye!";
}

int isFriday(int month, int day, int year) {

	int dayCount = 1, monthCount = 1, yearCount = 0, dayTotal = 0, dayTrack = 6, leapTester, result = 0;

	while (monthCount != month || dayCount != day || yearCount != year) {
		
		dayCount++;

		if (dayTrack == 6) {
			dayTrack = 0;
		}
		else {
			dayTrack++;
		}

		if (monthCount == 1 || monthCount == 3 || monthCount == 5 || monthCount == 7 || monthCount == 8 || monthCount == 10 || monthCount == 12) {
			dayTotal = 31;
		}
		else if (monthCount == 4 || monthCount == 6 || monthCount == 9 || monthCount == 11) {
			dayTotal = 30;
		}
		else if (monthCount == 2) {
			dayTotal = 28;
			leapTester = yearCount % 4;
			if (leapTester == 0) {
				dayTotal = 29;
			}
		}

		if (dayCount == dayTotal) {
			if (monthCount == 12) {
				if (yearCount == 99) {
					break;
				}
				yearCount++;
				monthCount = 1;
			}
			else {
				monthCount++;
			}
			dayCount = 0;

		}

		
	}
	if (dayTrack == 5) {
		result = 1;
	}
	else {
		result = 0;
	}
	return result;
}
