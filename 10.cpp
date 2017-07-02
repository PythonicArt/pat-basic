#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main(){

	int numbers[2010];
	const char* split=" ";
	char *p;
	char line[10000];
	cin.getline(line,10000);
	p=strtok(line, split);
	int count=0;
	while(p!=NULL)
	{
		numbers[count++]=atoi(p);
		p=strtok(NULL, split);
	}

	if(count%2!=0) return -1;

	if(count==2&&numbers[1]==0)
	{
		cout<<"0 0"<<endl;
		return 0;
	}

	for(int i=0;i<count-1;i+=2)
	{
		int a=numbers[i];
		int b=numbers[i+1];
		if(b!=0)
		{
			if(i>0) cout<<" ";
			cout<<a*b<<" "<<b-1;	
		}
	}
	
	cout<<endl;

};