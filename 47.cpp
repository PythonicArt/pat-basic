#include <iostream>
#include <map>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    map<int, int> m;
    map<int, int>::iterator it;
    int maxnum = 0, maxgrade = 0;
    for (size_t i = 0; i < n; i++) {
        int num, id, grade;
        scanf("%d-%d %d", &num, &id, &grade);
        it = m.find(num);
        if (it != m.end()) {
            it->second += grade;
        } else
            m[num] = grade;
        it = m.find(num);
        if (it->second > maxgrade) {
            maxgrade = it->second;
            maxnum = it->first;
        }
    }
    cout << maxnum << " " << maxgrade;
}
