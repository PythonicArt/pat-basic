#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

struct Fraction {
	long long numerator;
	long long denominator;
	Fraction() {}
	Fraction(long long n, long long d) {
		numerator = n;
		denominator = d;
	}

	Fraction operator+(Fraction f1) {
		Fraction sum;
		sum.numerator = this->numerator * f1.denominator +
		                this->denominator * f1.numerator;
		sum.denominator = this->denominator * f1.denominator;
		return sum;
	}

	Fraction operator-(Fraction f1) {
		Fraction sum;
		sum.numerator = this->numerator * f1.denominator -
		                this->denominator * f1.numerator;
		sum.denominator = this->denominator * f1.denominator;
		return sum;
	}

	Fraction operator*(Fraction f1) {
		Fraction sum;
		sum.numerator = this->numerator * f1.numerator;
		sum.denominator = this->denominator * f1.denominator;
		return sum;
	}

	Fraction operator/(Fraction f1) {
		Fraction sum;
		long long c1 = this->numerator * f1.denominator;
		long long c2 = this->denominator * f1.numerator;
		if (c2 < 0) {    //确保PrintFraction函数的b是正数
			c2 = -c2;
			c1 = -c1;
		}
		sum.numerator = c1;
		sum.denominator = c2;
		return sum;
	}
};

long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}

string GetBrife(Fraction fraction) {
	stringstream result;
	if (fraction.denominator == 0)
		return "Inf";
	long long interger = abs(fraction.numerator / fraction.denominator);
	long long left = abs(fraction.numerator % fraction.denominator);
	long long d = abs(fraction.denominator);
	int sign = 0;

	if (interger == 0 and left == 0)
		return "0";
	if (fraction.numerator < 0)
	{
		sign = 1;
	}

	if (interger != 0) {
		result << interger;
	}
	if (left != 0) {
		if (interger != 0)
			result << " ";
		long long cd = gcd(left, d);
		result << left / cd << "/" << d / cd;
	}

	if (sign == 1) {
		string minus = "(-)";
		return minus.insert(2, result.str());
	}
	return result.str();
}

string GetOutput(Fraction num1, Fraction num2) {
	stringstream result;
	string bnum1 = GetBrife(num1);
	string bnum2 = GetBrife(num2);

	result << bnum1 << " + " << bnum2 << " = " << GetBrife(num1 + num2) << "\n";
	result << bnum1 << " - " << bnum2 << " = " << GetBrife(num1 - num2) << "\n";
	result << bnum1 << " * " << bnum2 << " = " << GetBrife(num1 * num2) << "\n";

	string quotient;
	if (bnum2 == "0")
		quotient = "Inf";
	else
		quotient = GetBrife(num1 / num2);
	result << bnum1 << " / " << bnum2 << " = " << quotient;
	return result.str();
}

int main()
{
	long long a, b, c, d;
	scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
	Fraction num1(a, b);
	Fraction num2(c, d);
	cout << GetOutput(num1, num2) << endl;
}