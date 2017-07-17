#include <cmath>
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {
  int n, m, tol;
  cin >> m >> n >> tol;
  int points[n + 2][m + 2];
  std::map<int, int> cmap;
  int site[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                    {0, 1},   {1, -1}, {1, 0},  {1, 1}};
  for (int i = 0; i < n + 2; i++) {
    for (int j = 0; j < m + 2; j++) {
      if (i == 0 or j == 0 or i == n + 1 or j == m + 1) {
        points[i][j] = -tol;
      } else {
        cin >> points[i][j];
        ++cmap[points[i][j]];
      }
    }
  }

  bool unique = true;
  int result[3];
  int validcout = 0;

  for (size_t i = 1; i < n + 1; i++) {
    for (size_t j = 1; j < m + 1; j++) {
      int num = points[i][j];
      bool valid = true;

      for (size_t k = 0; k < 8; k++) {
        int a = i + site[k][0];
        int b = j + site[k][1];
        if (abs(num - points[a][b]) <= tol) {
          valid = false;
          break;
        }
      }

      if (valid) {
        if (cmap[num] > 1) {
          continue;
        }
        ++validcout;
        if (validcout > 1) {
          unique = false;
          break;
        } else {
          result[0] = j;
          result[1] = i;
          result[2] = num;
        }
      }
    }
    if (not unique) {
      break;
    }
  }
  if (not unique) {
    cout << "Not Unique" << endl;
  } else if (validcout == 1) {
    printf("(%d, %d): %d", result[0], result[1], result[2]);
  } else
    cout << "Not Exist" << endl;
  return 0;
}
