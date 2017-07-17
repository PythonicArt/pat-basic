// C/C++实现
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  int m, n, s;
  string tmp;
  bool flag = true; // 判断是否中奖
  map<string, int> map;
  scanf("%d %d %d", &m, &n, &s);
  int nextIndex = s;
  for (int i = 1; i <= m; ++i) {
    cin >> tmp;
    if (i == nextIndex) {
      if (map[tmp] == 0) { // 中奖
        cout << tmp << endl;
        ++map[tmp];
        flag = false;
        nextIndex += n;
      } else {
        ++nextIndex;
      }
    }
  }
  if (flag) {
    printf("Keep going...\n");
  }
  return 0;
}
