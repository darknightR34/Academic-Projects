/*
	Calendar Printer

	PSEUDOCODE:
	(0) PRINT welcome message
	(1) GET from user a month number (between 1 and 12)
	(2) GET from user amount of days in the month (between 28 and 31)
	(3) GET from user starting day of week (between Sun-Sat = 0-6)
		*Repeat (1) - (3) if user enters invalid values*
	(4) PRINT month name and day name formatted with propper spacing
	(5) PRINT incrementing number of days going to next line after Sat.
	(6) GET choice from user to repeat another month or exit program
		*Repeat (1) - (6) until user selects (n)*
	(7) PRINT goodbye message

	Created 1-25-2020 by Dario Calle Reyes

	*/
#include<iostream>;
#include<iomanip>;

using namespace std;

int main()
{
	char userCHOICE = 'y';
	int monthNUM = -1;
	int totalDAYS = 0;
	int startDAY = -2;

	// (0) PRINT welcome message
	cout << " Welcome to Calendar Printer!" << endl;

	while (userCHOICE != 'n') {
		// (1) GET from user a month number (between 1 and 12)
		while (monthNUM < 1 || monthNUM > 12) {
			cout << " Enter a month (1 to 12): ";
			cin >> monthNUM;
		}

		// (2) GET from user amount of days in the month (between 28 and 31)
		while (totalDAYS < 28 || totalDAYS > 31) {
			cout << " Enter days in the month (28, 29, 30, 31): ";
			cin >> totalDAYS;
		}

		// (3) GET from user starting day of week (between Sun-Sat = 0-6)
		while (startDAY < 0 || startDAY > 6) {
			cout << " Enter start day (0 to 6): ";
			cin >> startDAY;
		}

		// (4) PRINT month name and day name formatted with propper spacing
		if (monthNUM == 1) {
			cout << " JANUARY" << endl;
		}
		else if (monthNUM == 2) {
			cout << " FEBRUARY" << endl;
		}
		else if (monthNUM == 3) {
			cout << " MARCH" << endl;
		}
		else if (monthNUM == 4) {
			cout << " APRIL" << endl;
		}
		else if (monthNUM == 5) {
			cout << " MAY" << endl;
		}
		else if (monthNUM == 6) {
			cout << " JUNE" << endl;
		}
		else if (monthNUM == 7) {
			cout << " JULY" << endl;
		}
		else if (monthNUM == 8) {
			cout << " AUGUST" << endl;
		}
		else if (monthNUM == 9) {
			cout << " SEPTEMBER" << endl;
		}
		else if (monthNUM == 10) {
			cout << " OCTOBER" << endl;
		}
		else if (monthNUM == 11) {
			cout << " NOVEMBER" << endl;
		}
		else if (monthNUM == 12) {
			cout << " DECEMBER" << endl;
		}

		cout << " --- --- --- --- --- --- ---" << endl;
		cout << " Sun Mon Tue Wed Thr Fri Sat" << endl;
		cout << " --- --- --- --- --- --- ---" << endl;

		if (startDAY > 0) {
			cout << setw(4 * startDAY) << " "; // Adapts the width of the output to accomodate for the start day of the month
		}

		// (5) PRINT incrementing number of days going to next line after Sat.
		for (int i = 1; i <= totalDAYS; i++) {
			cout << setw(4); // sets the width for numbers to be 4 spaces
			cout << i;

			if (startDAY == 6) {
				cout << endl; // using the startDAY variable, everytime it reaches Sun, it jumps to the next line
				startDAY = 0;
			}
			else {
				startDAY += 1; // uses startDAY as a counter to determine when the startDAY is six so that a new line may be started in the next iteration
			}
		}

		// (6) GET choice from user to repeat another month or exit program
		cout << "\n Would you like to print another month? (y/n) ";
		cin >> userCHOICE;
		cout << endl;

		// RESET variables to original values given in the beginning
		monthNUM = -1;
		totalDAYS = 0;
		startDAY = -2;
	}
	// (7) PRINT goodbye message
	cout << " Thank you for using this program. Goodbye!";

	return 0;
}
