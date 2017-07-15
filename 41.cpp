// C/C++实现（AC代码）
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string ID;
    int trysite, site;
    map<int, pair<string, int>> info;

    for (int i = 0; i < n; ++i) {
        cin >> ID >> trysite >> site;
        info[trysite] = pair<string, int>(ID, site);
    }

    int qnum;
    int num;

    cin >> qnum;
    for (int i = 0; i < qnum; ++i) {
        cin >> num;
        map<int, pair<string, int>>::iterator it = info.find(num);
        if (it != info.end()) {
            pair<string, int> pit = it->second;
            cout << pit.first << " " << pit.second << endl;
        }
    }
}
