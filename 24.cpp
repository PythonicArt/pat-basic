#include <string>
#include <sstream>
#include <iostream>

using namespace std;

string PrintNum(string snum)
{
	string base;
	string exponent;

	int splitindex=snum.find('E');

	stringstream result;
	char basesign=snum.at(0);
	if(basesign=='-')
		result<<basesign;

	char esign=snum.at(splitindex+1);
	base=snum.substr(1,splitindex-1);
	exponent=snum.substr(splitindex+2);
	int exnum=stoi(exponent);
	if (exnum==0) 
	{
		result<<base;
		return result.str();
	}
	int tmp=base.find('.');
	base.erase(tmp,1);
	// result<<base<<" "<<exponent;
	if(esign=='-'){
		int count0=exnum-1;
		result<<"0.";
		while((count0--)>0) result<<"0";
		result<<base;
	}
	else if(esign=='+'){
		int temp=base.length()-1;
		int count0=exnum-temp;
		if(count0<0)
		{
			int inindex=base.length()+count0;
			base.insert(inindex,".");
			result<<base;
		}
		else{
			result<<base;
			while((count0--)>0) result<<"0";
		}
	}
	return result.str();
}

int main(){
	string input;
	cin>>input;
	cout<<PrintNum(input)<<endl;
}