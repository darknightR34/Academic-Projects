#include <iostream>;
#include <cstdlib>;
#include <ctime>;
#include <iomanip>;

using namespace std;

char coinFlip();

int main()
{
	srand(time(0));
	int flipTIMES;
	double headPROB;
	char userCHOICE = 'y', result;

	while (userCHOICE != 'n') {
		
		int Hcounter = 0;
		

		cout << " How many times would you like to toss your coin? ";
		cin >> flipTIMES;

		for (int i = 1; i <= flipTIMES; i++) {
			result = coinFlip();
			int noDigits = 0;
			int attemptNo = i;
			while (attemptNo != 0) {
				attemptNo /= 10;
				noDigits += 1;
			}

			if (result == 'H') {
				Hcounter += 1;

			}
			cout << " " << i << ":" << setw(8-noDigits) << result << endl;
		}
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);
		
		headPROB = (Hcounter / double(flipTIMES)) * 100;
		cout << " The probability of getting heads is : " << headPROB << "%" << endl;
		cout << " Would you like to run the program again (y/n)? ";
		cin >> userCHOICE;
	}
	cout << " Thank you for using the program, goodbye!";

	return 0;
}



char coinFlip()
{
	
	int low = 1, high = 2;

	

	int randomNum = rand() % (high - low + 1) + low;

	if (randomNum == 1) {
		return 'H';
	}
	else if (randomNum == 2) {
		return 'T';
	}
}