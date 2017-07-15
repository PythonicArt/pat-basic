#include <iostream>
#include <vector>

using namespace std;

struct question {
  int points;
  int answernum;
  int answer;
  question(int p, int an, int a) {
    points = p;
    answernum = an;
    answer = a;
  }
};

int main(int argc, char const *argv[]) {
  int qn, sn;
  cin >> sn >> qn;
  std::vector<question> v;
  int wronginfo[qn];
  for (size_t i = 0; i < qn; i++) {
    wronginfo[i] = 0;
  }
  int sinfo[sn];
  for (size_t i = 0; i < sn; i++) {
    sinfo[i] = 0;
  }

  for (size_t i = 0; i < qn; i++) {
    int p, an;
    int tmp;
    cin >> p >> tmp >> an;
    int a = 0;
    for (size_t j = 0; j < an; j++) {
      char c;
      cin >> c;
      int m = c - 'a';
      a |= 1 << m;
    }
    struct question newq(p, an, a);
    v.push_back(newq);
  }
  int maxwrong = 0;
  int maxnum = 0;
  for (size_t i = 0; i < sn; i++) {
    for (size_t j = 0; j < qn; j++) {
      char ac = ' ';
      while (ac != '(')
        cin >> ac;
      std::vector<question>::iterator it = v.begin() + j;
      int num;
      cin >> num;
      bool wrong = false;
      if (num == it->answernum) {
        int a = 0;
        for (size_t k = 0; k < num; k++) {
          char c;
          cin >> c;
          int m = c - 'a';
          a |= 1 << m;
        }
        if (a == it->answer) {
          sinfo[i] += it->points;
        } else
          wrong = true;
      } else {
        wrong = true;
      }
      if (wrong) {
        ++wronginfo[j];
        if (wronginfo[j] > maxwrong) {
          maxwrong = wronginfo[j];
          maxnum = 1;
        } else if (wronginfo[j] == maxwrong) {
          ++maxnum;
        }
      }
      while (ac != ')')
        cin >> ac;
    }
  }

  // output infomation
  for (size_t i = 0; i < sn; i++) {
    cout << sinfo[i] << endl;
  }
  if (maxwrong == 0) {
    cout << "Too simple" << endl;
  } else {
    cout << maxwrong << " ";
    for (size_t j = 0; j < qn; j++) {
      if (wronginfo[j] == maxwrong) {
        cout << j + 1;
        if (--maxnum > 0)
          cout << " ";
      }
    }
  }
  return 0;
}
