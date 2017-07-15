// C/C++实现（AC代码）
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;
    string Print = "PATest";
    int sum = 0;
    map<char, int> info;
    map<char, int>::iterator it;
    for (int i = 0; i < str.length(); ++i) {
        char c = str[i];
        if (Print.find(c) == -1)
            continue;
        it = info.find(c);
        if (it != info.end()) {
            it->second++;
        } else {
            info[c] = 1;
        }
        sum++;
    }

    while (sum > 0) {
        for (int i = 0; i < 6; ++i) {
            char c = Print[i];
            it = info.find(c);
            if (it != info.end()) {
                if (it->second > 0) {
                    cout << c;
                    it->second -= 1;
                    sum--;
                }
            }
        }
    }
}
