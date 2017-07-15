#include <iostream>
using namespace std;

void GetAnswer(int *answer, int m) {
  for (size_t i = 0; i < m; i++) {
    cin >> answer[i];
  }
}

int main(int argc, char const *argv[]) {
  int n, m;
  cin >> n >> m;
  int points[m];
  for (size_t i = 0; i < m; i++) {
    cin >> points[i];
  }
  int sinfo[n];
  for (size_t i = 0; i < n; i++) {
    sinfo[i] = 0;
  }
  int answer[m];
  GetAnswer(answer, m);
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      int tmp;
      cin >> tmp;
      if (tmp == answer[j]) {
        sinfo[i] += points[j];
      }
    }
  }
  for (size_t i = 0; i < n; i++) {
    cout << sinfo[i] << endl;
  }
  return 0;
}
