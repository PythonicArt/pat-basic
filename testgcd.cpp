// testgcd.cpp
#include "math.h"
#include "stdio.h"
#include <algorithm>
#include <cstring>
#include <fstream>
#include <gtest/gtest.h>
#include <sstream>
#include <string>

#include "code/35.cpp"
using namespace std;

int m;
TEST(GcdTest, IntTest) {
    ifstream in("input");
    ifstream rin("result");
    if (not in || not rin)
        perror("input");
    else {
        //**********data define*********
        string input;
        string split, rsplit;
        string rline;
        //**********data define*********
        int n;
        bool result = false;
        // rin>>result;
        while (in >> split and split == "-") {
            in >> n;
            int a[n], b[n];
            for (int i = 0; i < n; ++i)
                in >> a[i];
            for (int i = 0; i < n; ++i)
                in >> b[i];

            //**********get input*********
            while (getline(rin, rsplit) and rsplit == "-") {
                rin >> result;
            }
            // cout<<"jsdkfjsdkf "<<result<<endl;
            // cout<<GetOutput(broken,input)<<endl;
            int site = IsInsertSort(a, b, n);
            for (int i = 0; i < n; ++i) {
                cout << a[i] << " ";
            }
            cout << endl;
            for (int i = 0; i < n; ++i) {
                cout << b[i] << " ";
            }
            cout << site << endl;

            if (site != -1) {
                sort(b, b + site + 1);
                for (int i = 0; i < n; ++i) {
                    cout << b[i] << " ";
                }
            } else {
                MergeToNext(a, b, n);
            }
            cout << endl;
            // EXPECT_EQ(result, IsInsertSort(a, b, n));
        }

        //*********fileclse************
        in.close();
        rin.close();
    }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
