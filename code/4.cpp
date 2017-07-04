#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(void)
{
	int n;
	int maxGrade=0,minGrade=100;
	char name1[100],name2[100],num1[100], num2[100],name[100],num[100];
	int grade;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>name>>num>>grade;
		
		if (grade>maxGrade)
		{
			strcpy(name1,name);
			strcpy(num1,num);
			maxGrade=grade;
		}
		if (grade<minGrade)
		{
			strcpy(name2,name);
			strcpy(num2,num);
			minGrade=grade;
		}
	}

	cout<<name1<<" "<<num1<<endl;
	cout<<name2<<" "<<num2<<endl;
	return 0;
};