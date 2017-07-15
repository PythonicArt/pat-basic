//C/C++实现（AC代码）
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    long long countT = 0, countAT = 0, countPAT = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == 'T') {
            ++countT;
        }
        else if (s[i] == 'A') {
            countAT += countT;
        }
        else if (s[i] == 'P') {
            countPAT += countAT;
        }
    }
    printf("%lld\n", countPAT % (long long)1000000007);
    return 0;
}