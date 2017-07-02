//testgcd.cpp
#include <gtest/gtest.h>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int Gcd(int a, int b)    //计算最大公约数
{
    return 0 == b ? a : Gcd(b, a % b); 
}

TEST(GcdTest, IntTest)
{
	int num=7764;
	char tmp[10000];
	
	while(num!=6174)
	{
		sprintf(tmp,"%d",num);
		string high(tmp);
		string low(tmp);
		sort(high.rbegin(),high.rend());
		sort(low.begin(),low.end());
		int h,l;
		h=stoi(high);
		l=stoi(low);
		// EXPECT_EQ(7764,h);
		// EXPECT_EQ(4677,l);
		num=h-l;
		cout<<h<<"-"<<l<<"="<<num<<endl;
	}

    EXPECT_EQ(6174,num);
    // EXPECT_EQ(2, Gcd(2, 5));
    // EXPECT_EQ(2, Gcd(2, 4))<<"hello";
    // EXPECT_EQ(3, Gcd(6, 9))<<"hello";
    // EXPECT_EQ(2, Gcd(6, 10))<<"hello";
    // cout
}

// TEST(GcdTest, IntTest2)
// {
//     // EXPECT_EQ(1, Gcd(2, 5));
//     // EXPECT_EQ(2, Gcd(2, 5));
//     // EXPECT_EQ(2, Gcd(2, 4))<<"hello";
//     EXPECT_EQ(3, Gcd(6, 9))<<"hello";
//     // EXPECT_EQ(2, Gcd(6, 10))<<"hello";
//     // cout
// }

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}