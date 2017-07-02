#include <stdio.h>
#include <math.h>
//AC

bool IsPrime(int num){
	for(int i=2;i<=sqrt(num);i++)
	{
		if(num%i==0) return false;
	}
	return true;
}

int NextPrime(int num){
	while(IsPrime(++num)==false);
	return num;
}

int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	int count=n-m+1;
	int num=2;

	for(int i=1;i<m;i++)
	{
		num=NextPrime(num);
	}

	for(int i=1;i<=count;i++)
	{
		printf("%d",num);
		num=NextPrime(num);
		if(i<count)
		{
			if(i%10==0) printf("\n");
			else printf(" ");
		}
	}
}