#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
bool myfunction(int i, int j) { return (i > j); }

void BuildSpiral(vector<int> &v, int **&matrix, int row, int column) {
    int round = 0;
    int stage = 1;
    int i = round;
    int j = round;
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        matrix[i][j] = *it;
        if (stage == 1) {
            ++j;
            if (j == column - round) {
                --j;
                ++i;
                ++stage;
            }
        } else if (stage == 2) {
            ++i;
            if (i == row - round) {
                --i;
                --j;
                ++stage;
            }
        } else if (stage == 3) {
            --j;
            if (j < round) {
                ++j;
                --i;
                ++stage;
            }
        } else if (stage == 4) {
            --i;
            if (i == round) {
                ++i;
                ++j;
                stage = 1;
                ++round;
            }
        }
    }
}

void FindRowAndColumn(int n, int &row, int &column) {
    for (size_t mid = sqrt(n); mid > 1; mid--) {
        if (n % mid == 0) {
            row = n / mid;
            column = mid;
            break;
        }
    }
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    std::vector<int> v(n);
    for (size_t i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), myfunction);
    int row = 0, column = 0;
    FindRowAndColumn(n, row, column);
    int **matrix;
    matrix = new int *[row];
    for (int i = 0; i < row; i++) {
        matrix[i] = new int[column];
    }
    BuildSpiral(v, matrix, row, column);

    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < column; j++) {
            cout << matrix[i][j];
            if (j < column - 1)
                cout << " ";
            else
                cout << "\n";
        }
    }
    return 0;
}
