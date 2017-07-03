#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int IsInsertSort(int* array, int* next, int n) {
	int i = 1;
	for (i = 1; i < n; ++i)
	{
		if (next[i] < next[i - 1])
			break;
	}
	if (equal(array + i, array + n, next + i))
		return i;
	return -1;
}

void MergeToNext(int* init, int* next, int n) {
	vector<int> tmp(n);
	copy(init, init + n, tmp.begin());
	bool quit = false;

	for (int i = 2; ; i *= 2)
	{
		if (i > n) {
			i = n - 1;
			quit = true;
		}

		if (equal(tmp.begin(), tmp.end(), next)) {
			quit = true;
		}

		for (int j = 0; j < n ; j += i)
		{
			vector<int>::iterator start = tmp.begin() + j;
			vector<int>::iterator end = (i + j >= n) ? tmp.end() : tmp.begin() + i + j;
			sort(start, end);
		}

		if (quit == true) {
			for (int i = 0; i < n; ++i)
			{
				cout << tmp[i];
				if (i < n - 1) cout << " ";
			}
			break;
		}

	}
}

int mains() {
	int n;
	cin >> n;
	if (n <= 0)
		return 0;
	int init[n], next[n];
	for (int i = 0; i < n; ++i) cin >> init[i];
	for (int i = 0; i < n; ++i) cin >> next[i];

	int site = IsInsertSort(init, next, n);
	if (site != -1) {
		if (site < n)
			sort(next, next + site + 1);
		cout << "Insertion Sort" << endl;
		for (int i = 0; i < n; ++i)
		{
			cout << next[i];
			if (i < n - 1) cout << " ";
		}
	}
	else {
		cout << "Merge Sort" << endl;
		MergeToNext(init, next, n);
	}
}
