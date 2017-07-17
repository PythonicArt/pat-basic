// C/C++实现
#include <iostream>

using namespace std;

int main() {
  int m, n, a, b, r;
  scanf("%d %d %d %d %d", &m, &n, &a, &b, &r);
  int tmp;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &tmp);
      if (j != 0) {
        printf(" ");
      }
      if (tmp >= a && tmp <= b) {
        printf("%03d", r);
      } else {
        printf("%03d", tmp);
      }
    }
    printf("\n");
  }
  return 0;
}
