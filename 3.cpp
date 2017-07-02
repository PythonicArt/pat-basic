//C/C++实现
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

bool IsOK(const char* str){
	int countP=0,countT=0;
	int iLength=strlen(str);
	for(int i=0;i<iLength;i++)
	{
		char c=str[i];
		if(c!='P'&&c!='A'&&c!='T')
			return false;
		if(c=='P')
		{
			countP++;
			if (countP>1)
				return false;
		}
		if(c=='T')
		{
			countT++;
			if (countT>1)
				return false;
		}
	}
	if(countP!=1||countT!=1)
		return false;

	string s=str;
	int indexP,indexT;
	indexP=s.find('P');
	indexT=s.find('T');

	int a,b,c;
	a=indexP;
	b=indexT-indexP-1;
	c=iLength-indexT-1;
	if(a*b!=c||b==0)
		return false; 
	return true;
}

int main(){
	int n;
	char* str;
	scanf("%d",&n);

	for(int i=0;i<n;i++)
	{
		scanf("%s",str);
		if (IsOK(str)){
			printf("YES\n");
		}
		else
			printf("NO\n");
	}
    return 0;
}

void test3(){
	const char* testArray[8]={"PAT","PAAT","AAPATAA","AAPAATAAAA",
						"xPATx","PT","Whatever","APAAATAA"};
	for(int i=0;i<8;i++)
	{
		if (IsOK(testArray[i]))
		{
			printf("YES\n");
		}
		else
			printf("NO\n");
	}
}