#include <iostream>
#include <iomanip>
using namespace std;

class Apparel
{
protected:
	double price, taxRate;
public:
	Apparel();
	Apparel(double _price, double _taxRate);
	double priceAfterTax() const;
	virtual void print() const = 0;
};

class Top :public Apparel
{
private:
	char topSize;
public:
	Top();
	Top(double _price, double _taxRate, char _topSize);
	void print() const;
};

class Shorts :public Apparel
{
private:
	int waist;
	char thickness;
public:
	Shorts();
	Shorts(double _price, double _taxRate, int _waist, char _thickness);
	void print()const;
};

int main() {
	Apparel* baseP = new Top(6.49, 7.5, 's');
	baseP->print();
	cout << endl;
	baseP = new Shorts(32.16, 6.0, 42, 'h');
	baseP->print();
}

Apparel::Apparel()
	:price(0.0), taxRate(0.0) {}

Apparel::Apparel(double _price, double _taxRate)
	: price(_price), taxRate(_taxRate) {}

double Apparel::priceAfterTax() const {
	return (price * (1 + taxRate/100));
}

Top::Top()
	:topSize('z') {}

Top::Top(double _price, double _taxRate, char _topSize)
	: Apparel(_price, _taxRate), topSize(_topSize) {}

void Top::print() const {
	string tempString;
	if (topSize == 's'){
		tempString = "small";
	}
	else if (topSize == 'm') {
		tempString = "medium";
	}
	else {
		tempString = "large";
	}

	cout << " You bought a top with " << tempString << " size." << endl;
	cout << fixed << setprecision(1) << ' ' << taxRate << "% tax was applied." << endl;
	cout << fixed << setprecision(2) << " Price before tax: $" << price << endl;
	cout << fixed << setprecision(2) << " Price after tax: $" << priceAfterTax() << endl;

}

Shorts::Shorts()
	:waist(0), thickness('z') {}

Shorts::Shorts(double _price, double _taxRate, int _waist, char _thickness)
	: Apparel(_price, _taxRate), waist(_waist), thickness(_thickness) {}

void Shorts::print()const {
	string tempString2;
	if (thickness == 'l') {
		tempString2 = "light";
	}
	else if (thickness == 'm') {
		tempString2 = "medium";
	}
	else {
		tempString2 = "heavy";
	}
	cout << " You bought a pair of "<< tempString2 << "shorts with W" << waist << " inches." << endl;
	cout << fixed << setprecision(1) << ' ' << taxRate << "% tax was applied." << endl;
	cout << fixed << setprecision(2) << " Price before tax: $" << price << endl;
	cout << fixed << setprecision(2) << " Price after tax: $" << priceAfterTax() << endl;
}