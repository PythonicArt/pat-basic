#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
    int num;
    double sum = 0;
    int cnum = 0;
    cin >> num;
    string input;
    for (size_t i = 0; i < num; i++) {
        cin >> input;
        int dotNum = 0;
        bool bValid = true;
        bool minus = false;
        size_t j = 0;
        if (input[0] == '-') {
            minus = true;
            j = 1;
        }
        for (; j < input.size(); j++) {
            char c = input[j];
            if (c < '0' or c > '9') {
                if (c != '.') {
                    bValid = false;
                    break;
                } else {
                    dotNum++;
                    if (dotNum > 1) {
                        bValid = false;
                        break;
                    } else if (j == 0) {
                        bValid = false;
                        break;
                    } else if (j == 1 and minus == true) {
                        bValid = false;
                        break;
                    } else if (j < input.size() - 3) {
                        bValid = false;
                        break;
                    }
                }
            }
        }
        if (bValid) {
            double value = stod(input);
            if (value < -1000 or value > 1000)
                bValid = false;
            else {
                sum += value;
                ++cnum;
            }
        }
        if (not bValid)
            cout << "ERROR: " << input << " is not a legal number" << endl;
    } // end all input

    double avg = sum / cnum;
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    cout.precision(2);
    if (cnum == 0) {
        cout << "The average of 0 numbers is Undefined" << endl;
    } else if (cnum == 1) {
        cout << "The average of 1 number is " << avg << endl;
    } else {
        cout << "The average of " << cnum << " numbers is " << avg << endl;
    }
    return 0;
}
