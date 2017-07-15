#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    double sum = 0;
    for (size_t i = 0; i < n; i++) {
        double num, tmp;
        cin >> num;
        tmp = num * ((n - i) * (i + 1));
        sum += tmp;
    }
    cout.precision(2);
    // std::cout.setf(std::ios::fixed, std::ios::floatfield);
    cout << sum << endl;
}

// abcde
//
// a ab abc abcd abcde   a:0:5 n*1  (n-i)*(i+1)
//
// b bc bcd bcde b:1:4+4 n-1*2
//
// c cd cde 　c:2:3+3+3 n-2*3
//
// d de  d:3:2+2+2+2  n-3*4
//
// e	e:4:1+1+1+1+1  (n-4)*5
