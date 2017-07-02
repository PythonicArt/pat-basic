//testgcd.cpp
#include <gtest/gtest.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include "stdio.h"
#include "math.h"

#include "34.cpp"
using namespace std;


TEST(GcdTest, IntTest)
{
  ifstream in("input");
  ifstream rin("result");
  if (not in || not rin)
    perror("input");
  else
  {
    //**********data define*********
    string input, result;
    string split, rsplit;
    string rline;
    //**********data define*********

    // rin>>result;
    while (in >> split and split == "-")
    {
      int a, b, c, d;
      in >> a >> b >> c >> d;
      Fraction num1(a, b);
      Fraction num2(c, d);
      //**********get input*********
      while (getline(rin, rsplit) and rsplit == "-")
      {
        for (int i = 0; i < 4; i++) {
          getline(rin, rline);
          result.append(rline + '\n');
        }
      }
      // cout<<"jsdkfjsdkf "<<result<<endl;
      // cout<<GetOutput(broken,input)<<endl;
      EXPECT_EQ(result, GetOutput(num1, num2));
    }

    //*********fileclse************
    in.close();
    rin.close();
  }
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}