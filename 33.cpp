#include <iostream>
#include <sstream>

using namespace std;

string GetOutput(string broken,string input){
	stringstream result;

	int signArray[128]={0};

	for(int i=0;i<broken.length();++i){
		int index=broken[i];
		if (index>='A' and index<='Z')
		{
			signArray[index+32]=1;
		}
		
		signArray[index]=1;
	}

	if (signArray['+']==1)
	{
		for(int i='A';i<='Z';++i){
				signArray[i]=1;
		}
	}

	for(int i=0;i<input.length();++i){
		int index=input[i];
		if (signArray[index]!=1)
			result<<input[i];
	}
	return result.str();
}

int main(){
	string broken,input;
	getline(cin,broken);
    cin>>input;
    cout<<GetOutput(broken,input)<<endl;
}