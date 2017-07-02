//C/C++实现
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>

using namespace std;

int PrintBlackHole(int num)
{
	char tmp[10000];
	sprintf(tmp,"%04d",num);
	char c=tmp[0];
	int i;
	// if (num<1000||num>=10000) return -1;
	for(i=0;i<strlen(tmp);i++)
	{
		if(tmp[i]!=c)
			break;
	}
	if(i==strlen(tmp))
	{
		cout<<tmp<<" - "<<tmp<<" = "<<setfill('0')<<setw(strlen(tmp))<<"0"<<endl;
		return num;
	}

	while(true)
	{
		sprintf(tmp,"%04d",num);
		string high(tmp);
		string low(tmp);
		sort(high.rbegin(),high.rend());
		sort(low.begin(),low.end());
		int h,l;
		h=stoi(high);
		l=stoi(low);
		num=h-l;
		cout<<setfill('0')<<setw(4)<<high<<" - ";
		cout<<setfill('0')<<setw(4)<<low<<" = ";
		cout<<setfill('0')<<setw(4)<<num<<endl;
		if(num==6174)
			break;
	}
	return num;
}


int main()
{
	int num;
	cin>>num;
	PrintBlackHole(num);
}