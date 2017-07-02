#include <string>
#include <sstream>
#include <iostream>

using namespace std;

string PrintArrange(int* array){

	stringstream tmp;
	for(int i=0;i<10;i++)
	{
		int count=array[i];
		while(count>0)
		{
			tmp<<i;
			--count;
		}
	}
	string result=tmp.str();
	for(int i=0;i<result.length();i++)
	{
		if(result.at(i)!='0')
		{
			char c=result[0];
			result[0]=result[i];
			result[i]=c;
			break;
		}
	}
	return result;
}

int main(){
	int a[10]={0};
	for(int i=0;i<10;++i){
		cin>>a[i];
	}
	cout<<PrintArrange(a)<<endl;
}