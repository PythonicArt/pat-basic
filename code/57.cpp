#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char const *argv[]) {
    string line;
    getline(cin, line);
    int sum = 0;
    for (size_t i = 0; i < line.size(); i++) {
        char c = line[i];
        if (isalpha(c)) {
            c = tolower(c);
            sum += c - 'a' + 1;
        }
    }
    int tmp = sum;
    int count0 = 0, count1 = 0;
    while (tmp != 0) {
        if (tmp % 2 == 0) {
            ++count0;
        } else {
            ++count1;
        }
        tmp /= 2;
    }
    printf("%d %d\n", count0, count1);
    return 0;
}
