//C/C++实现（AC代码）
#include <iostream>
#include <string>
#include <map>
#include <ctype.h>

using namespace std;

int main() {
	string str;
	int a[128] = {0};
	int maxtimes = -1;
	int maxindex = -1;
	char c;
	while ((scanf("%c", &c)) != EOF)
	{
		if (isalpha(c)) {
			if (c >= 'A' and c <= 'Z')
				c = tolower(c);
			++a[c];
			if (a[c] > maxtimes or (a[c] == maxtimes and c < maxindex)) {
				maxtimes = a[c];
				maxindex = c;
			}
		}
	}
	c = maxindex;
	cout << c << " " << maxtimes << endl;
}