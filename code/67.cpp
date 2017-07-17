#include <iostream>
#include <string>

using namespace std;

int main() {
  int n, count = 0;
  string pwd, tmp;
  cin >> pwd >> n;
  cin.get(); //注意这里要把换行符给干掉。
  while (getline(cin, tmp) && tmp != "#") {
    ++count;
    if (pwd == tmp && count <= n) {
      printf("Welcome in\n");
      return 0;
    }
    if (pwd != tmp) {
      printf("Wrong password: ");
      cout << tmp << endl;
      if (count == n) {
        printf("Account locked\n");
        return 0;
      }
    }
  }
  return 0;
}
