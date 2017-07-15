#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int housenum, obDay;
    float threshValue;
    cin >> housenum >> threshValue >> obDay;
    float possibleNum = 0, emptyNum = 0;

    for (size_t i = 0; i < housenum; ++i) {
        int oDay;
        cin >> oDay;
        int count = 0;
        for (size_t j = 0; j < oDay; ++j) {
            float eNum;
            cin >> eNum;
            if (eNum < threshValue) {
                ++count;
            }
        }
        if (count > oDay / 2) {
            if (oDay > obDay) {
                ++emptyNum;
            } else
                ++possibleNum;
        }
    }

    float pRatio = possibleNum / housenum * 100;
    float eRatio = emptyNum / housenum * 100;
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    cout.precision(1);
    cout << pRatio << "% " << eRatio << "%" << endl;
    return 0;
}
