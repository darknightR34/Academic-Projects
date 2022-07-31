#include <iostream>
using namespace std;

class Rational
{
public:
	Rational();
	Rational(int _numerator);
	Rational(int _numerator, int _denominator);
	friend ostream& operator <<(ostream& output, const Rational& frac);
	friend istream& operator >>(istream& input, Rational& frac);
	friend Rational operator +(const Rational& lhs, const Rational& rhs);
	friend Rational operator -(const Rational& lhs, const Rational& rhs);
	friend Rational operator *(const Rational& lhs, const Rational& rhs);
	friend Rational operator /(const Rational& lhs, const Rational& rhs);
	friend bool operator ==(const Rational& lhs, const Rational& rhs);
	friend bool operator <(const Rational& lhs, const Rational& rhs);
	friend bool operator <=(const Rational& lhs, const Rational& rhs);
	friend bool operator >(const Rational& lhs, const Rational& rhs);
	friend bool operator >=(const Rational& lhs, const Rational& rhs);
	int GCD(int num, int den);
	void normalize();

private:
	int numerator, denominator;
};

int main()
{
	cout << " Testing the constructor and the overloaded << operator for a Rational object..." << endl;

	Rational x, y(2), z(-5, -6), w(1, -3);
	x.normalize(), y.normalize(), z.normalize(), w.normalize();

	cout << " 4 Rational objects, x, y(2), z(-5,-6), w(1,-3) are declared!" << endl;
	cout << " x = " << x << ", y = " << y << ", z = " << z << ", w = " << w << endl << endl;

	cout << " Testing the custom constructor with two arguments and normalization routine:" << endl;

	y = Rational(-128, -48);
	y.normalize();
	cout << " y = Rational(-128,-48) outputs as " << y << endl;

	y = Rational(-128, 48);
	y.normalize();
	cout << " y = Rational(-128,-48) outputs as " << y << endl;

	y = Rational(128, -48);
	y.normalize();
	cout << " y = Rational(-128,-48) outputs as " << y << endl;

	Rational a = (1, 1);
	a.normalize();
	cout << " Rational a(1,1) outputs as: " << a << endl;

	cout << " y * a = " << y << " * " << a << " = " << y * a << endl << endl;

	Rational f1, f2, f3;

	cout << " Enter a fraction in the format integer_numerator/integer_denominator:\n ";
	cin >> f1;
	f1.normalize();
	cout << " You entered the equivalent of: " << f1 << endl;

	cout << " Enter a fraction in the format integer_numerator/integer_denominator:\n ";
	cin >> f2;
	f2.normalize();
	cout << " You entered the equivalent of: " << f2 << endl;

	cout << " Enter a fraction in the format integer_numerator/integer_denominator:\n ";
	cin >> f3;
	f3.normalize();
	cout << " You entered the equivalent of: " << f3 << endl << endl;

	cout << " Testing the overloaded arithmetic and relational operators..." << endl;
	cout << ' ' << f1 << " + " << f2 << " = " << f1 + f2 << endl;
	cout << ' ' << f1 << " - " << f2 << " = " << f1 - f2 << endl;
	cout << ' ' << f1 << " * " << f2 << " = " << f1 * f2 << endl;
	cout << ' ' << f1 << " / " << f2 << " = " << f1 / f2 << endl;

	cout << ' ' << f1 << " == " << f1 << " = " << (f1 == f1) << endl;
	cout << ' ' << f1 << " == " << f2 << " = " << (f1 == f2) << endl;
	cout << ' ' << f2 << " == " << f2 << " = " << (f1 == f1) << endl;

	cout << ' ' << f1 << " < " << f1 << " = " << (f1 < f1) << endl;
	cout << ' ' << f1 << " < " << f2 << " = " << (f1 < f2) << endl;
	cout << ' ' << f2 << " < " << f2 << " = " << (f2 < f2) << endl;

	cout << ' ' << f1 << " <= " << f1 << " = " << (f1 <= f1) << endl;
	cout << ' ' << f1 << " <= " << f2 << " = " << (f1 <= f2) << endl;
	cout << ' ' << f2 << " <= " << f2 << " = " << (f2 <= f2) << endl;

	cout << ' ' << f1 << " > " << f1 << " = " << (f1 > f1) << endl;
	cout << ' ' << f1 << " > " << f2 << " = " << (f1 > f2) << endl;
	cout << ' ' << f2 << " > " << f2 << " = " << (f2 > f2) << endl;

	cout << ' ' << f1 << " >= " << f1 << " = " << (f1 >= f1) << endl;
	cout << ' ' << f1 << " >= " << f2 << " = " << (f1 >= f2) << endl;
	cout << ' ' << f2 << " >= " << f2 << " = " << (f2 >= f2) << endl << endl;

	cout << ' ' << f2 << " + " << f3 << " = " << f2 + f3 << endl;
	cout << ' ' << f2 << " - " << f3 << " = " << f2 - f3 << endl;
	cout << ' ' << f2 << " * " << f3 << " = " << f2 * f3 << endl;
	cout << ' ' << f2 << " / " << f3 << " = " << f2 / f3 << endl;

	cout << ' ' << f2 << " == " << f2 << " = " << (f2 == f2) << endl;
	cout << ' ' << f2 << " == " << f3 << " = " << (f2 == f3) << endl;
	cout << ' ' << f3 << " == " << f3 << " = " << (f3 == f3) << endl;

	cout << ' ' << f2 << " < " << f2 << " = " << (f2 < f2) << endl;
	cout << ' ' << f2 << " < " << f3 << " = " << (f2 < f3) << endl;
	cout << ' ' << f3 << " < " << f3 << " = " << (f3 < f3) << endl;

	cout << ' ' << f2 << " <= " << f2 << " = " << (f2 <= f2) << endl;
	cout << ' ' << f2 << " <= " << f3 << " = " << (f2 <= f3) << endl;
	cout << ' ' << f3 << " <= " << f3 << " = " << (f3 <= f3) << endl;

	cout << ' ' << f2 << " > " << f2 << " = " << (f2 > f2) << endl;
	cout << ' ' << f2 << " > " << f3 << " = " << (f2 > f3) << endl;
	cout << ' ' << f3 << " > " << f3 << " = " << (f3 > f3) << endl;

	cout << ' ' << f2 << " >= " << f2 << " = " << (f2 >= f2) << endl;
	cout << ' ' << f2 << " >= " << f3 << " = " << (f2 >= f3) << endl;
	cout << ' ' << f3 << " >= " << f3 << " = " << (f3 >= f3) << endl << endl;

	return 0;
}

Rational::Rational()
	:numerator(0), denominator(1)
{}
Rational::Rational(int _numerator)
	: numerator(_numerator), denominator(1)
{}
Rational::Rational(int _numerator, int _denominator)
	: numerator(_numerator), denominator(_denominator)
{}

ostream& operator <<(ostream& output, const Rational& frac) {
	output << frac.numerator << '/' << frac.denominator;
	return output;
}
istream& operator >>(istream& input, Rational& frac) {
	char space;
	input >> frac.numerator >> space >> frac.denominator;
	return input;
}

Rational operator +(const Rational& lhs, const Rational& rhs) {
	Rational sum;
	sum.denominator = lhs.denominator * rhs.denominator;
	sum.numerator = ((sum.denominator / lhs.denominator) * lhs.numerator) + ((sum.denominator / rhs.denominator) * rhs.numerator);
	sum.normalize();

	return sum;
}
Rational operator -(const Rational& lhs, const Rational& rhs) {
	Rational subs;
	subs.denominator = lhs.denominator * rhs.denominator;
	subs.numerator = ((subs.denominator / lhs.denominator) * lhs.numerator) - ((subs.denominator / rhs.denominator) * rhs.numerator);
	subs.normalize();
	return subs;
}
Rational operator *(const Rational& lhs, const Rational& rhs) {
	Rational mult;
	mult.numerator = lhs.numerator * rhs.numerator;
	mult.denominator = lhs.denominator * rhs.denominator;
	mult.normalize();

	return mult;
}
Rational operator /(const Rational& lhs, const Rational& rhs) {
	Rational div;
	div.numerator = lhs.numerator * rhs.denominator;
	div.denominator = lhs.denominator * rhs.numerator;
	div.normalize();

	return div;
}
bool operator ==(const Rational& lhs, const Rational& rhs) {
	if (lhs.numerator * rhs.denominator == rhs.numerator * lhs.denominator) {
		return true;
	}
	return false;
}
bool operator <(const Rational& lhs, const Rational& rhs) {
	int temp1, temp2;
	if (lhs.denominator != rhs.denominator) {
		temp1 = lhs.numerator * rhs.denominator;
		temp2 = rhs.numerator * lhs.denominator;
		if (temp1 < temp2) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (lhs.numerator < rhs.numerator) {
			return true;
		}
		return false;
	}
}

bool operator <=(const Rational& lhs, const Rational& rhs) {
	int temp1, temp2;
	if (lhs.denominator != rhs.denominator) {
		temp1 = lhs.numerator * rhs.denominator;
		temp2 = rhs.numerator * lhs.denominator;
		if (temp1 <= temp2) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		if (lhs.numerator <= rhs.numerator) {
			return 1;
		}
		return 0;
	}
}
bool operator >(const Rational& lhs, const Rational& rhs) {
	int temp1, temp2;
	if (lhs.denominator != rhs.denominator) {
		temp1 = lhs.numerator * rhs.denominator;
		temp2 = rhs.numerator * lhs.denominator;
		if (temp1 > temp2) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		if (lhs.numerator > rhs.numerator) {
			return 1;
		}
		return 0;
	}
}
bool operator >=(const Rational& lhs, const Rational& rhs) {
	int temp1, temp2;
	if (lhs.denominator != rhs.denominator) {
		temp1 = lhs.numerator * rhs.denominator;
		temp2 = rhs.numerator * lhs.denominator;
		if (temp1 >= temp2) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		if (lhs.numerator >= rhs.numerator) {
			return 1;
		}
		return 0;
	}
}

int Rational::GCD(int num, int den) {
	int size = num;

	if (num > den) {
		size = den;
	}

	int gcd = 1;

	for (int i = size; i > 0; i--) {
		if (num % i == 0 && den % i == 0) {
			gcd = i;
			break;
		}
	}

	return gcd;
}

void Rational::normalize() {
	if (denominator < 0) {
		denominator *= -1, numerator *= -1;
	}

	int gcd = GCD(abs(denominator), abs(numerator));
	numerator /= gcd, denominator /= gcd;
}