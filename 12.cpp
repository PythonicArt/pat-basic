#include <stdio.h>

int main(){
	int n,num=0;
	int array[5]={0,0,0,0,0};
	int s=-1;
	int dcount=0;
	int a1=false;

	scanf("%d",&n);

	for(int i=0;i<n;i++)
	{
		scanf("%d",&num);
		int m=num%5;
		if(num%10==0){
			a1=true;
			array[0]+=num;
		} 
		else if(m==1)
		{
			s*=-1; 
			array[1]+=s*num;
		}
		else if(m==2)
		{
			array[2]++;
		}
		else if(m==3)
		{
			array[3]+=num;
			dcount++;
		}
		else if(m==4)
		{
			array[4]=(num>array[4]?num:array[4]);
		}
	}

	double r3=(double)array[3]/dcount;

	for(int i=0;i<5;i++)
	{
		if (array[i]==0){
			if(i==0 && a1==true)
				printf("0");
			else
				printf("%c",'N');
		}
		else
		{	
			if(i==3)	
				printf("%.1f",r3);
			else 
				printf("%d",array[i]);
		}
		if(i<4) printf(" ");
	}
}