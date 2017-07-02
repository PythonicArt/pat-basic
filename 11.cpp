#include <stdio.h>

int main(){
	int n;
	long a,b,c;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		scanf("%ld%ld%ld",&a,&b,&c);
		const char* str="false";	
		if(a+b>c)	str="true";
		printf("Case #%d: %s",i+1,str);
		if(i<n-1)	printf("\n");		
	}
}
