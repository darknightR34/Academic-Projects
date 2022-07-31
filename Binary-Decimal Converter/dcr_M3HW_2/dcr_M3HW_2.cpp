/*
	Binary-Decimal Converter

	PSEUDOCODE: 
	(1) PRINT welcome message and the two options
	(2) GET choice from user (binary to decimal or vice versa)
	(3) GET from user a value to be converted
	(4) CALCULATE conversion of the value 
	(5) PRINT value before and after conversion
	(6) GET choice from user to repeat the program again
	(7) PRINT goodbye message

	Created 1-26-22 by Dario Calle Reyes 
*/
#include<iostream>;
#include<cmath> // this library was included to be able to calculate powers of values like (2^n or 10^n) by using the pow() function.

using namespace std;

int main()
{
	// initialize and declare variables
	int convertCHOICE;
	char userCHOICE = 'y';
	int initialVAL = 0;
	int copyVAL = 0;
	int compareVAL;
	int convertedVAL = 0;

	// (1) PRINT welcome message and the two options
	cout << " Welcome to the Binary-Decimal Converter!" << endl;

	// repeats program until user is satisfied
	while (userCHOICE != 'n') {
		// (2) GET choice from user 
		cout << " (1) Convert Decimal to Binary" << endl;
		cout << " (2) Convert Binary to Decimal" << endl;
		cout << " Choose an option (Enter 1 or 2): ";
		cin >> convertCHOICE;

		// this if statement initializes the conversion from decimal to binary
		if (convertCHOICE == 1) {
			// (3) GET from user a value to be converted
			cout << " Enter a decimal number: ";
			cin >> initialVAL;
			copyVAL = initialVAL; // creates a copy of the user input to be manipulated in the conversion 

			// (4) CALCULATE conversion of the value
			for (int i = 0; i < initialVAL; i++) {
				compareVAL = pow(2, i); // this variable is used to find the largest power of 2 that is less than the desired number to convert
				
				if (copyVAL <= compareVAL) { // once the value used in the comparison is larger than the desired number
					copyVAL -= pow(2, (i - 1)); // update the copy of the value created by substracting the value before the compareVAL was larger than the desired number (2^(i-1))
					convertedVAL += pow(10, (i - 1)); // updates the final value of the conversion while the copyVAL is not zero (10^(i-1))
					i = 0; // restart the i variable in the for loop so that it starts from 0 to find the new largest value that fits inside the copyVAL
				}
				if (copyVAL == 0) {
					break; // once copyVAL is 0 the converesion has been completed
				}
				}
			// (5) PRINT value before and after conversion
			cout << " " << initialVAL << " converted to binary: " << convertedVAL << endl;
			}
		// this else if statement takes care of the conversion from binary to decimal
		else if (convertCHOICE == 2) {
			// (3) GET from user a value to be converted
			cout << " Enter a binary number: ";
			cin >> initialVAL;
			copyVAL = initialVAL;

			// (4) CALCULATE conversion of the value
			for (int i = 0; i < initialVAL; i++) { // this is the same as in case 1 but instead it find the largest power of 10 that fits into the binary number and convertedVAl updates by adding the powers of 2 that make copyVAL = 0
				compareVAL = pow(10, i);

				if (copyVAL <= compareVAL) {
					copyVAL -= pow(10, (i - 1));
					convertedVAL += pow(2, (i - 1)); // 
					i = 0;
				}
				if (copyVAL == 0) {
					break;
				}
			}
			// (5) PRINT value before and after conversion
			cout << " " << initialVAL << " converted to decimal: " << convertedVAL << endl;
		}

		// (6) GET choice from user to repeat the program again
		cout << " Would you like to use the converter again (y/n)? ";
		cin >> userCHOICE;
		cout << endl;
		initialVAL = 0;
		convertedVAL = 0;
		}
	// (7) PRINT goodbye message
	cout << " Thank you for using this program. Goodbye!";

	return 0;
	}
