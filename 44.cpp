#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
  int n = 0;
  string lowsite[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun",
                        "jly",  "aug", "sep", "oct", "nov", "dec"};
  string highsite[13] = {"",    "tam", "hel", "maa", "huh", "tou", "kes",
                         "hei", "elo", "syy", "lok", "mer", "jou"};
  cin >> n;
  cin.clear();
  cin.ignore();
  for (int i = 0; i < n; i++) {
    string sLine;
    getline(cin, sLine);
    char c = sLine.at(0);

    if (isdigit(c)) {
      int left = std::stoi(sLine);
      bool havehigh = false;
      while (left >= 13) {
        int j = left / 13;
        if (j > 0) {
          cout << highsite[j];
          havehigh = true;
        }
        left %= 13;
        if (left > 0)
          cout << " ";
      }
      if (left > 0 or (left == 0 and !havehigh)) {
        cout << lowsite[left];
      }
      cout << endl;
    } else {
      int len = sLine.length();
      int exponent = 0;
      int sum = 0;
      for (int i = len - 3; i >= 0; i -= 4) {
        string str = sLine.substr(i, 3);
        if (exponent == 0) {
          for (int j = 0; j < 13; j++) {
            if (str == lowsite[j]) {
              sum += j;
              break;
            }
          }
          exponent++;
        }
        for (int j = 1; j < 13; j++) {
          if (str == highsite[j]) {
            sum += j * pow(13, exponent);
            exponent++;
            break;
          }
        }
      }
      cout << sum << endl;
    }
  }
  return 0;
}
