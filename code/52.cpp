#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    std::vector<string> signs[3];
    for (size_t i = 0; i < 3; i++) {
        string line;
        getline(cin, line);
        bool signStart = false;
        stringstream tmp;
        for (size_t j = 0; j < line.size(); j++) {
            char c = line[j];
            if (not signStart and c == '[') {
                signStart = true;
                tmp.str("");
            } else if (signStart) {
                if (c == ']') {
                    signStart = false;
                    signs[i].push_back(tmp.str());
                } else {
                    tmp << c;
                }
            }
        }
    }
    int n;
    cin >> n;
    int sequence[5] = {0, 1, 2, 1, 0};
    for (size_t i = 0; i < n; i++) {
        stringstream temp;
        bool bValid = true;
        for (size_t j = 0; j < 5; j++) {
            int indexofset = sequence[j];
            int index;
            cin >> index;
            if (index > signs[indexofset].size() or index < 1) {
                bValid = false;
                break;
            }
            --index;
            temp << signs[indexofset][index];
            if (j == 0) {
                temp << "(";
            }
            if (j == 3) {
                temp << ")";
            }
        }
        if (bValid) {
            cout << temp.str() << endl;
        } else {
            cout << "Are you kidding me? @\\/@" << endl;
        }
    }
    return 0;
}
