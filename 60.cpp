#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  int a[n];
  for (size_t i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  int E = -1;
  for (size_t i = 0; i < n; i++) {
    int num = a[i] - 1;
    if (n - i >= num) {
      if (num > E) {
        E = num;
      }
    }
  }
  cout << E << endl;
  return 0;
}
