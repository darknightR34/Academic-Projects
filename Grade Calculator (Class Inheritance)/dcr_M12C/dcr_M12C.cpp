#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Scores
{
public:
	void getScores();
	void print() const;
protected:
	int scoreAmount;
	double* scoresList;
};

class Percentage :public Scores
{
public:
	void calcPercentage();
	void print() const;
protected:
	double percent;
};

class Grade :public Percentage
{
public:
	void calcGrade();
	void print() const;
private:
	string letterGrade;
};

int main()
{
	Grade g1;

	g1.getScores();

	g1.calcPercentage();

	g1.calcGrade();
	g1.print();

	return 0;
}

void Scores::getScores() {
	cout << " How many scores would you like to enter? ";
	cin >> scoreAmount;

	scoresList = new double[scoreAmount];

	cout << " Enter " << scoreAmount << " scores separated by a space: ";
	for (int i = 0; i < scoreAmount; i++) {
		cin >> scoresList[i];
	}
}

void Scores::print() const {
	cout << " Assignments Scores: " << endl;
	for (int i = 0; i < scoreAmount; i++) {
		cout << fixed << setprecision(1) << " Assignment " << i + 1 << ": " << scoresList[i] << endl;
	}
}

void Percentage::calcPercentage() {
	double sum = 0.0;

	for (int i = 0; i < scoreAmount; i++) {
		sum += scoresList[i];
	}

	percent = sum / scoreAmount;
	percent = round(percent * 10.0) / 10.0;
}

void Percentage::print() const {

	Scores::print();
	cout << "\n Total Percentage: " << percent << "%" << endl;
}

void Grade::calcGrade() {
	if (percent <= 100 && percent >= 90.0) {
		letterGrade = "A";
	}
	else if (percent <= 89.9 && percent >= 87.0) {
		letterGrade = "A-";
	}
	else if (percent <= 86.9 && percent >= 84.0) {
		letterGrade = "B+";
	}
	else if (percent <= 83.9 && percent >= 80.0) {
		letterGrade = "B";
	}
	else if (percent <= 79.9 && percent >= 77.0) {
		letterGrade = "B-";
	}
	else if (percent <= 76.9 && percent >= 74.0) {
		letterGrade = "C+";
	}
	else if (percent <= 73.9 && percent >= 70.0) {
		letterGrade = "C";
	}
	else if (percent <= 69.9 && percent >= 67.0) {
		letterGrade = "C-";
	}
	else if (percent <= 66.9 && percent >= 64.0) {
		letterGrade = "D+";
	}
	else if (percent <= 63.9 && percent >= 60.0) {
		letterGrade = "D";
	}
	else if (percent <= 59.9 && percent >= 57.0) {
		letterGrade = "D-";
	}
	else if (percent <= 59.9 && percent >= 0) {
		letterGrade = "E";
	}
}

void Grade::print()const {
	Percentage::print();
	cout << " Final Grade : " << letterGrade;
	cout << endl;
}