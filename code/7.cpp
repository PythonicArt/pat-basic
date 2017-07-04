#include <stdio.h>
#include <math.h>
//AC

bool IsPreimer(int num){
	for(int i=2;i<=sqrt(num);i++)
	{
		if(num%i==0) return false;
	}
	return true;
}

int main(){
	int n;
	int pre=0;
	int count=0;
	scanf("%d",&n);

	for(int i=1;i<=n;i++)
	{
		if (IsPreimer(i))
		{
			if(i-pre==2)
			{
				count++;
			}
			pre=i;
		}
	}
	printf("%d\n",count);
}