#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool fncomp(pair<string, int> left, pair<string, int> right) {
    if (left.second == right.second) {
        return left.first < right.first;
    }
    return left.second > right.second;
}
int main(int argc, char const *argv[]) {
    int n, k;
    cin >> n >> k;
    string name;
    int height;
    std::vector<pair<string, int>> v;
    for (size_t i = 0; i < n; i++) {
        cin >> name >> height;
        pair<string, int> tmp;
        tmp.first = name;
        tmp.second = height;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), fncomp);
    // cout << "\n";
    // for (std::vector<pair<string, int>>::iterator it = v.begin(); it <
    // v.end();
    //      it++) {
    //     cout << it->first << " " << it->second << endl;
    // }
    int num = n / k;
    std::vector<pair<string, int>>::iterator it = v.begin();
    int lastend = 0;
    for (size_t i = 0; i < k; ++i) {
        int rownum = i == 0 ? num + n % k : num;
        int start = lastend;
        int end = start + rownum;
        lastend = end;
        if (rownum % 2 == 0) {
            it = v.begin() + end - 1;
        } else {
            it = v.begin() + end - 2;
        }
        for (; it > v.begin() + start; it -= 2) {
            cout << it->first << " ";
            --rownum;
        }
        for (it = v.begin() + start; it < v.begin() + end; it += 2) {
            cout << it->first;
            --rownum;
            if (rownum >= 1)
                cout << " ";
            else
                cout << "\n";
        }
    }
    return 0;
}
