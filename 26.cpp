#include "stdio.h"


int main(){

	int a,b,c;
	scanf("%d %d",&a,&b);

	c=(b-a)/100;
	if((b-a)%100>=50) ++c;

	int hour,min,sec;
	hour=c/3600;
	min=c%3600/60;
	sec=c-3600*hour-60*min;
	printf("%02d:%02d:%02d\n", hour,min,sec);
}