#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    int num1 = 0, num2 = 0;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        int aWin = 0, bWin = 0;
        int aSay, bSay, aShow, bShow;
        cin >> aSay >> aShow >> bSay >> bShow;
        int sum = aSay + bSay;
        if (aShow == sum) {
            aWin = 1;
            ++num1;
        }
        if (bShow == sum) {
            bWin = 1;
            ++num2;
        }
        if (aWin + bWin == 2) {
            --num1;
            --num2;
        }
    }
    cout << num2 << " " << num1;
    return 0;
}
