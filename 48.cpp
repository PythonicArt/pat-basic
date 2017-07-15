#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    unsigned char site[3] = {'J', 'Q', 'K'};
    string a, b;
    cin >> a >> b;
    int len1, len2;
    len1 = a.size();
    len2 = b.size();
    if (len1 > len2) {
        b.insert(0, len1 - len2, '0');
    } else {
        a.insert(0, len2 - len1, '0');
    }
    int bEven = -1;
    if (a.size() % 2 == 0) {
        bEven *= -1;
    }
    for (size_t i = 0; i < a.size(); i++) {
        int left = a[i] - '0';
        int right = b[i] - '0';
        if (bEven == 1) {
            int result = right - left;
            result = result >= 0 ? result : result + 10;
            cout << result;
        } else {
            int result = (right + left) % 13;
            if (result > 9) {
                cout << site[result - 10];
            } else
                cout << result;
        }
        bEven *= -1;
    }
    return 0;
}
