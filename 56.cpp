#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    int num;
    std::vector<int> v;
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
    }
    int sum = 0;
    for (std::vector<int>::iterator it = v.begin(); it < v.end(); it++) {
        for (std::vector<int>::iterator jt = it + 1; jt < v.end(); jt++) {
            int a = *it;
            int b = *jt;
            sum += a * 10 + b;
            sum += b * 10 + a;
        }
    }
    cout << sum << endl;
    return 0;
}
