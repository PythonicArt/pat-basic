// C/C++实现
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    vector<int> big(n); //存入当前下标前面的最大的数
    int max = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
        big[i] = max;
        if (v[i] > max) { //更新最大值
            max = v[i];
        }
    }
    int small = 1000000001;
    vector<int> result;
    for (int i = n - 1; i >= 0; --i) {
        if (v[i] > big[i] && v[i] < small) {
            result.push_back(v[i]);
        }
        if (v[i] < small) { //更新最小值
            small = v[i];
        }
    }
    int size = result.size();
    printf("%d\n", size);
    if (size - 1 >= 0) { //不加判断的话，如果没有符合的情况，会下标越界
        printf("%d", result[size - 1]);
    }
    for (int i = size - 2; i >= 0; --i) {
        printf(" %d", result[i]);
    }
    printf("\n");
    return 0;
}
