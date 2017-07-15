// C/C++实现
#include <iostream>

using namespace std;

int award[10001];
int prime[10001];

int main() {
  // create prime table
  prime[1] = 1; // 1不是素数
  for (int i = 2; i <= 5000; ++i) {
    for (int j = 2; i * j <= 10000; ++j) {
      prime[i * j] = 1; // 1为非素数
    }
  }
  // input
  int n;
  scanf("%d", &n);
  int tmp;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &tmp);
    if (i == 1) {
      award[tmp] = 1; //神秘大奖
    } else {
      if (prime[i] == 0) { // 是素数
        award[tmp] = 2;    //小黄人
      } else {
        award[tmp] = 3; //巧克力
      }
    }
  }
  int k;
  scanf("%d", &k);
  for (int i = 0; i < k; ++i) {
    scanf("%d", &tmp);
    printf("%04d: ", tmp);
    if (award[tmp] == 0) {
      printf("Are you kidding?\n");
    } else if (award[tmp] == 1) {
      printf("Mystery Award\n");
      award[tmp] = -1; //已经查询过
    } else if (award[tmp] == 2) {
      printf("Minion\n");
      award[tmp] = -1; //已经查询过
    } else if (award[tmp] == 3) {
      printf("Chocolate\n");
      award[tmp] = -1; //已经查询过
    } else if (award[tmp] == -1) {
      printf("Checked\n");
    }
  }
  return 0;
}
