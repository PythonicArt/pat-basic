#include <stdio.h>
#include <string.h>
#include <math.h>
#define min(a,b) a<b?a:b

int main(){
	char array[4][60];
	char tmp[60];
	const char* rDay[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
	int len1,len2;
	int day=-1,hour=-1,min;

	for(int i=0;i<4;i++)
	{
		scanf("%s",array[i]);
	}

	len1=min(strlen(array[0]),strlen(array[1]));
	len2=min(strlen(array[2]),strlen(array[3]));

	for(int i=0;i<len1;i++)
	{
		char c1=array[0][i];
		char c2=array[1][i];

		if(c1==c2)
		{
			if (day==-1)
			{
				if(c1>='A' && c1<='G')
				{
					day=c1-'A';
				}
				continue;
			}
			else if (hour==-1)
			{
				if(c1>='0' && c1<='9')
				{
					hour=c1-'0';
					break;
				}
				if(c1>='A' && c1<='N')
				{
					hour=c1-'A'+10;
					break;
				}
			}
		}
	}


	for(int i=0;i<len2;i++)
	{
		char c1=array[2][i];
		char c2=array[3][i];

		if(c1==c2)
		{
			if((c1>='a' && c1<='z') or (c1>='A' && c1<='Z'))
			{
					min=i;
					break;
			}
		}
	}
	
	printf("%s %02d:%02d\n",rDay[day],hour,min);

}