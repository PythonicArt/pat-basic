#include <iostream>

using namespace std;
int main(){

	int weight[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	char verify[12]="10X98765432";

	string input;
	int n;
	cin>>n;
	
	int correctnum=0;
	for(int j=0;j<n;++j)
	{
		int sum=0;
		cin>>input;
		for(int i=0;i<17;++i){
			if(not( input[i]<='9' and input[i]>='0'))
			{
					cout<<input<<'\n';
					sum=-1;
					break;
			}
			int num=input[i]-'0';
			sum+=num*weight[i];
		}
		if(sum!=-1)
		{
			int left=sum%11;
			if(verify[left]==input[17])
				++correctnum;
			else
				cout<<input<<'\n';
		}
		
	}
	if(correctnum==n)
		cout<<"All passed"<<endl;
}