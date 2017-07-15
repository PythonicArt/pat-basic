#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  std::map<int, int> smap;
  for (size_t i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    smap[a] = b;
    smap[b] = a;
  }
  int m;
  cin >> m;
  std::vector<int> single;
  std::vector<int> msingle;
  std::map<int, int>::iterator it;
  int array[100000];
  for (size_t i = 0; i < m; i++) {
    int num;
    cin >> num;
    it = smap.find(num);
    if (it == smap.end()) {
      single.push_back(num);
    } else
      msingle.push_back(num);
    array[num] = 1;
  }
  for (size_t i = 0; i < msingle.size(); i++) {
    int a = msingle.at(i);
    int b = smap[a];
    if (array[b] == 0) {
      single.push_back(a);
    }
  }
  sort(single.begin(), single.end());
  cout << single.size() << endl;
  for (size_t i = 0; i < single.size(); i++) {
    int num = single.at(i);
    std::cout << std::setfill('0') << std::setw(5);
    cout << num;
    if (i < single.size() - 1) {
      cout << " ";
    }
  }
  return 0;
}
