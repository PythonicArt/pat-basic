#include <stdio.h>
#include <stdlib.h>

void Reverse(int* array,int start,int end){
	for(;start<end;start++,end--)
	{
		int tmp=array[start];
		array[start]=array[end];
		array[end]=tmp;
	}
}

int main(){
	int n,m;
	int *num;
	scanf("%d%d",&n,&m);
	num=(int *)malloc(sizeof(int)*n);
	

	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}

	int k=m%n;
	Reverse(num, 0, n-k-1);
	Reverse(num, n-k, n-1);
	Reverse(num, 0, n-1);

	for(int i=0;i<n;i++){
		printf("%d",*(num+i));
		if(i!=n-1)
		{
			printf(" ");
		}
	}
	
	free(num);
	num=NULL;
	return 0;
}