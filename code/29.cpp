#include <iostream>

using namespace std;

int main(){
	string line1,line2;
	cin>>line1>>line2;
	int a[128]={0};
	for(int i=0;i<line1.length();i++)
	{
		char c=line1.at(i);
		if(line2.find(c)==-1)
		{
			if(c>= 'a'&&c<= 'z')  
            	c-=32;
            if (a[c]==0)
            {
            		cout<<c; 
            		a[c]=1;
            }
		}
	}
	cout<<endl;
}