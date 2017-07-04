#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
//AC

int nextnum(int num)
{
	if (num == 1) return 1;
	if (num % 2 == 0) return num / 2;
	return (3 * num + 1) / 2;
}


void findKeyNums(int *array, int n = 0)
{

	int rList[100] = {0};
	int sList[10000] = {0}; //this is a fucking array.
	int min = 101;

	for (int i = 0; i < n; i++)
	{
		int num = array[i];
		if (num > 1)
			rList[num] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		int num = array[i];
		while (num > 1)
		{
			int next = nextnum(num);
			if (next > 1 && next <= 100)
				rList[next] = 0;
			if (sList[next] == 0)
			{
				sList[next] = 1;
				num = next;
			}
			else
			{
				break;
			}
		}
	}

	for (int i = 0; i < 100; i++)
		if (rList[i] == 1)
		{
			min = i;
			break;
		}

	if (min > 100) return;

	for (int i = 100; i > 0; i--)
		if (rList[i] == 1)
		{
			if (i != min)
				printf("%d ", i);
			else
			{
				printf("%d\n", i);
				break;
			}
		}
}


int main()
{
	int array[100];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", array + i);
	findKeyNums(array, n);
}



