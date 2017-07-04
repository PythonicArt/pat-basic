# include <iostream>
# include <map>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	int num;
	map<int, int> m;
	map<int, int>::iterator it;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> num;
		it = m.find(num);
		if (it != m.end())
			m[num]++;
		else
			m[num] = 1;
	}
	int n2;
	cin >> n2;
	for (int i = 0; i < n2; ++i)
	{
		cin >> num;
		it = m.find(num);
		if (it != m.end())
			cout << it->second;
		else
			cout << 0;
		if (i < n2 - 1)
		{
			cout << " ";
		}
	}
}