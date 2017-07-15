#include <cmath>
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[]) {
    double R1, P1, R2, P2;
    cin >> R1 >> P1 >> R2 >> P2;
    double R = R1 * R2;
    double P = P1 + P2;

    double A, B;
    A = R * cos(P);
    B = R * sin(P);
    stringstream result;
    result.setf(std::ios::fixed, std::ios::floatfield);
    result.precision(2);
    if (A > -0.005 and A < 0.005) {
        result << 0.00;
    } else
        result << A;

    if (B > -0.005 and B < 0.005) {
        result << "+0.00i" << endl;
    } else if (B < 0) {
        result << "-" << abs(B) << "i" << endl;
    } else if (B > 0) {
        result << "+" << B << "i" << endl;
    }

    cout << result.str();
    return 0;
}
