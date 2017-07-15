#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  std::set<int> v;
  for (size_t i = 0; i < n; i++) {
    string num;
    cin >> num;
    int number = 0;
    for (int j = num.size() - 1; j >= 0; --j) {
      int tmp = num.at(j) - '0';
      number += tmp;
    }
    v.insert(number);
  }

  cout << v.size() << endl;
  int i = 0;
  for (set<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *it;
    if (i++ < v.size() - 1) {
      cout << " ";
    }
  }
  return 0;
}
