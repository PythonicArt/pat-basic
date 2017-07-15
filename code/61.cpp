#include <iostream>

using namespace std;

int GetAnswer(int m) {
  int answer = 0;
  for (size_t i = 0; i < m; i++) {
    int tmp;
    cin >> tmp;
    answer |= tmp << i;
  }
  return answer;
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
  int answer = GetAnswer(m);
  // cout << "The true answer is " << answer << endl;
  for (size_t i = 0; i < n; i++) {
    int sanswer = GetAnswer(m);
    // cout << "The answer of student" << i << " is " << sanswer << endl;
    int result = sanswer ^ answer;
    // cout << "The result of student " << i << " is " << result << "\n" <<
    // endl;
    for (size_t j = 0; j < m; j++) {
      int tmp = result & 1;
      if (tmp == 0) {
        sinfo[i] += points[j];
      }
      result >>= 1;
    }
  }
  for (size_t i = 0; i < n; i++) {
    cout << sinfo[i] << endl;
  }
  return 0;
}
