# include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int a1, a2, a3;
	int b1, b2, b3;
	scanf("%d.%d.%d %d.%d.%d", &a1, &a2, &a3, &b1, &b2, &b3);
	int a = b1, b = b2, c = b3;
	long sum, sum1, sum2;
	sum1 = a1 * 17 * 29 + a2 * 29 + a3;
	sum2 = b1 * 17 * 29 + b2 * 29 + b3;
	sum = sum2 - sum1;
	if (sum < 0) {
		cout << "-";
		sum = abs(sum);
	}
	a = sum / (17 * 29);
	b = (sum - a * 17 * 29) / 29;
	c = sum - a * 17 * 29 - b * 29;
	cout << a << "." << b << "." << c << endl;
}