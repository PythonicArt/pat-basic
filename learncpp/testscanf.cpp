#include <stdio.h>


void TestSpace();

int main(void){

	TestSpace();
}

void TestEOF()
{
	char str[100];
	char c;
	int count;

	while((scanf("%c",&c))!=EOF)
	{
		str[count++]=c;
	}
	int i=0;
	while(i<count) printf("%c",str[i++]);
	printf("\n");
}


void TestSpace(){
	char a,b,c;
	int m,n,o;
	scanf("%c %c %c",&a,&b,&c);
	printf("%c%c%c\n",a,b,c);

	scanf("%d%d%d",&m,&n,&o);
	printf("%d %d %d\n",m,n,o);
}