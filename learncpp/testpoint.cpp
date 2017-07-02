#include <stdio.h>
#include <iostream>

using namespace std;


int sum(int a,int b){
	return a+b;
}

int* reverse(int *nums){
	return nums;
}

void TestFuncPointer()
{
	int (*p)(int,int);
	p=sum;
	cout<<p(1,2)<<endl;
	cout<<(*p)(1,2)<<endl;
	
	int a[10]={1,2,3};
	int* q=reverse(a);
	cout<<*q<<endl;
}

void TestConstPointer()
{
	char a[3]="a";
	char b[3]="b";
	char* const q=b;
	const char* p="hello";

	// q=a;  false assignment of read-only variable ‘q’
	// p[0]='s';false assignment of read-only location ‘* p’
	p=a; //true
	cout<<*p<<endl;
	q[0]='s';
	cout<<*q<<endl;

}

extern void Print();

int main(){
	TestConstPointer();
	const char *s="sdfsdfsdf";
	int const aa=1;
	Print();
}