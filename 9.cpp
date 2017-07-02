#include <iostream>
#include <string.h>

using namespace std;

int main(){

	char sArray[100];
	char* tArray[100];
	int count=0;
	int i=0;
	const char * split=" ";
	cin.getline(sArray,100);

	char *p = strtok(sArray,split); 
	while(p!=NULL) 
	{ 
		tArray[count++]=p;
		p = strtok(NULL,split); 
	}

	for(i=count-1;i>0;i--)
	{
		cout<<tArray[i]<<" ";
	}
	cout<<tArray[0]<<endl;
}