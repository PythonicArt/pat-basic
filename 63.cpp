#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  long long max = 0;
  for (size_t i = 0; i < n; i++) {
    long long real, virt;
    cin >> real >> virt;
    long long sum = real * real + virt * virt;
    if (sum > max) {
      max = sum;
    }
  }
  double result = sqrt(max);
  cout.precision(2);
  std::cout.setf(std::ios::fixed, std::ios::floatfield);
  cout << result << endl;
  return 0;
}
