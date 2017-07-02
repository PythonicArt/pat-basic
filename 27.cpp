#include "stdio.h"
#include "math.h"

int main(){

	int num,left;
	char c;
	scanf("%d %c",&num,&c);

	int n=sqrt((num+1)/2);
	int use=2*n*n-1;
	left=num-use;

	int m=2*n-1;
	int spacenum=0;
	for(int i=0;i<m;++i){
		int xnum=m-2*spacenum;
		for(int j=0;j<spacenum;++j)
			printf(" ");
		for(int j=0;j<xnum;++j)
			printf("%c",c);
		// for(int j=0;j<spacenum;++j)
		// 	printf(" ");
		printf("\n");
		if(i<n-1)
			++spacenum;
		else
			--spacenum;
	}
	printf("%d\n",left);

}



