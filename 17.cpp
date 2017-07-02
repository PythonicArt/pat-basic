//C/C++实现
#include <iostream>
#include <string>

using namespace std;


int toInt(char c){
	return c-'0';
}

char toChar(int i){
	return i+'0';
}

string divide(string num,int n){
	string shang;
	int left=0;

	for(int i=0;i<num.length();i++){
		int mid=left*10+toInt(num[i]);
		shang+=toChar(mid/n);
		left=mid%n;
	}

	string str(shang);
	if(shang[0]=='0'&&shang.length()!=1){
		str=str.substr(1);
	}
	string l(1,toChar(left));
	str+=" "+l;
	return str;
}

int main(){
	string num;
	int n;
	cin>>num>>n;
	cout<<divide(num,n)<<endl;
}