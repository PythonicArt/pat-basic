//C/C++实现
#include "stdio.h"
#include "string.h"
#include <string>
#include <sstream>

std::string countnum(std::string num){
	std::stringstream ss;
	int result[10]={0};
	int i=0;
	while(num.at(i)=='0') i++;

	while(i<num.length())
	{
		int index=num[i++]-48;
		result[index]++;
	}
	for(i=0;i<10;i++)
	{
		if(result[i]!=0)
			ss<<i<<":"<<result[i]<<"\n";
	}
	return ss.str();
}

// int main(){
// 	char num[1000];
// 	scanf("%s",num);
// 	countnum(num);
// }