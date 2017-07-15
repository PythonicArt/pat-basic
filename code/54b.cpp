// C/C++实现
#include <iostream>
#include <sstream>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    string tmp;
    double tmp_d;
    int tmp_i;
    stringstream ss;
    int correctCount = 0;
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        bool correct = true;
        bool minus = false;
        if (tmp[0] == '-') {
            minus = true;
        }
        int count = 0; //计算小数点的个数
        int j = (minus == false ? 0 : 1);
        for (; j < tmp.size(); ++j) {
            if (tmp[j] == '.') {
                ++count;
                if (count > 1) { //小数点个数超过1
                    correct = false;
                    break;
                }
            } else if (tmp[j] >= '0' && tmp[j] <= '9') {
                continue;
            } else { //非小数点非数字
                correct = false;
                break;
            }
        }
        if (!correct) {
            cout << "ERROR: " << tmp << " is not a legal number" << endl;
        } else {
            if (count == 0) { //整数
                ss << tmp;
                ss >> tmp_i;
                ss.clear(); //重置stringstream的状态标志
                ss.str(""); //清空数据
                if (tmp_i < -1000 || tmp_i > 1000) {
                    correct = false;
                } else {
                    sum += tmp_i;
                    ++correctCount;
                }
            } else { //小数
                int point = tmp.find('.');
                if (tmp.size() - point > 3) { //小数点后面超过2位
                    correct = false;
                }
                // else if(point == tmp.size() - 1){ //小数点在最后一位，也不对
                //    correct = false;
                //}
                else if (minus == true && point == 1) { //形如：-.x
                    correct = false;
                } else if (minus == false && point == 0) { //形如：.x
                    correct = false;
                } else {
                    ss << tmp;
                    ss >> tmp_d;
                    ss.clear(); //重置stringstream的状态标志
                    ss.str(""); //清空数据
                    if (tmp_d < -1000 || tmp_d > 1000) {
                        correct = false;
                    } else {
                        sum += tmp_d;
                        ++correctCount;
                    }
                }
            }
            if (!correct) {
                cout << "ERROR: " << tmp << " is not a legal number" << endl;
            }
        }
    }
    if (correctCount == 0) {
        printf("The average of 0 numbers is Undefined\n");
    } else if (correctCount == 1) {
        printf("The average of 1 number is %.2f\n", sum);
    } else {
        printf("The average of %d numbers is %.2f\n", correctCount,
               sum / correctCount);
    }
    return 0;
}
