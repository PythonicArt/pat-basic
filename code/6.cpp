#include <stdio.h>
//AC
int main()
{
	int n;
	scanf("%d",&n);
	int a=n/100;
	int b=(n-a*100)/10;
	int c=n%10;
	for(int i=0;i<a;i++)
		printf("B");
	for(int i=0;i<b;i++)
		printf("S");
	for(int i=1;i<=c;i++)
		printf("%d",i);
	return 0;
}