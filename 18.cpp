#include <iostream>
#include <string.h>

using namespace std;


char maps[3]={'B','C','J'};

int getindex(char c){
	for(int i=0;i<3;i++){
		if (c==maps[i]) return i;
	}
	return -1;
}

void staticrace(int n,string* strarray)
{
	char a,b;
	int resultA[3]={0};
	int actionW[3]={0};
	int actionF[3]={0};

	//judge
	for(int i=0;i<n;i++)
	{
		string str=strarray[i];
		a=str[0];
		b=str[2];
		//record action
		//draw game
		int m=getindex(a);
		int n=getindex(b);
		if(a==b)
		{
			resultA[1]++;
		}
		//A win
		else if((a=='C'&&b=='J')||(a=='J'&&b=='B')||(a=='B'&&b=='C'))
		{
			resultA[0]++;
			actionW[m]++;
		}
		else
		{
			resultA[2]++;
			actionF[n]++;
		}
	}
	//print result A
	cout<<resultA[0]<<" "<<resultA[1]<<" "<<resultA[2]<<endl;
	cout<<resultA[2]<<" "<<resultA[1]<<" "<<resultA[0]<<endl;
	
	int max1=-1,max2=-1;
	int xi,ii;
	for(int i=0;i<3;i++)
	{
		if(actionW[i]>max1) 
		{
				max1=actionW[i];
				xi=i;
		}

		if(actionF[i]>max2) 
		{
				max2=actionF[i];
				ii=i;
		}
	}
	cout<<maps[xi]<<" "<<maps[ii]<<endl;
}


int main(){
	int n;
	char a,b;
	string str[100000];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		string l(1,a);
		string m(1,b);
		str[i]=l+" "+m;
	}

	staticrace(n,str);
}