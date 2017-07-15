#include <iostream>
using namespace std;

int main() {
    int max = 0, mscore = 0;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n + 1; ++i)
        a[i] = 0;

    for (int i = 0; i < n; ++i) {
        int num, score;
        cin >> num >> score;
        a[num] += score;
        if (a[num] > mscore) {
            mscore = a[num];
            max = num;
        }
    }
    cout << max << " " << mscore << endl;
}
