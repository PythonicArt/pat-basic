#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool allCompared(int low, int high, vector<int> num, int site, int c) {
    if (high > num.size()) {
        return false;
    }
    if (low == high) {
        return true;
    }

    if (c == '>') {
        for (size_t i = low; i < high; i++) {
            if (num[i] < num[site]) {
                return false;
            }
        }
        return true;
    } else if (c == '<') {
        for (size_t i = low; i < high; i++) {
            if (num[i] > num[site]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    std::vector<int> a(n);
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }

    int count = 0;
    std::vector<int> v(n);
    for (size_t i = 0; i < n; i++) {
        if (not allCompared(0, i, a, i, '<'))
            continue;
        if (not allCompared(i + 1, n, a, i, '>'))
            continue;
        v[count++] = a[i];
    }
    sort(v.begin(), v.begin() + count);
    cout << count << endl;
    for (size_t i = 0; i < count; i++) {
        cout << v[i];
        if (i < count - 1)
            cout << " ";
    }
    return 0;
}
