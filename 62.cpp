#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
  int temp;
  while (b) {
    /*利用辗除法，直到b为0为止*/
    temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

int main(int argc, char const *argv[]) {
  int n1, m1, n2, m2, k;
  scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &k);
  std::vector<int> v;
  for (size_t i = 1; i < k; i++) {
    if (i != 1 and gcd(k, i) != 1) {
      continue;
    } else {
      int low, high;
      low = n1 * k;
      high = n2 * k;
      int t1, t2;
      if (low > high) {
        swap(low, high);
        t1 = i * m2;
        t2 = i * m1;
      } else {
        t1 = i * m1;
        t2 = i * m2;
      }
      if (t1 > low and t2 < high) {
        v.push_back(i);
      }
    }
  }
  for (std::vector<int>::iterator it = v.begin(); it < v.end(); it++) {
    cout << *it << "/" << k;
    if (it < v.end() - 1) {
      cout << " ";
    }
  }
  return 0;
}
