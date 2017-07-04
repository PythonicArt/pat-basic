#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int countsum(int count,int num){
	int sum=0;
	for(int i=0;i<count;i++){
		sum+=num*pow(10,i);
	}
	return sum;
}

int getamount(char *m,char c)
{
	int count=0;
	int len=strlen(m);
	for(int i=0;i<len;i++){
		if(m[i]==c)	count++;
	}
	return count;
}

int count16(char* m,char m1,char* n,char n1){
	int acount=0,bcount=0;
	acount=getamount(m,m1);
	bcount=getamount(n,n1);
	int sum=0;
	int num1=m1-'0';
	int num2=n1-'0';
	// printf("%d %d %d %d\n",acount,num1,bcount,num2);
	return countsum(acount,num1)+countsum(bcount,num2);
}

// int main(){
// 	char a[10],b[10];
// 	char c,d;
// 	scanf("%s %c %s %c",a,&c,b,&d);
// 	printf("%d\n",count16(a,c,b,d));
// }
	// char a[100]="3862767";
	// char b[100]="13530293";
	// char c='6';
	// char d='3';