#include <stdio.h>
#include <stdlib.h>

char sequence[20];
char buffer[20];
char dnaSeq[5] = "ACGT";
int t, n, m, solve;

int cmpBases(int b1, int b2)
{
	return (b1 != b2);
}

void btMutations(int index, int k, int it)
{
    int c;
	int i = it;
	if(k <= m)
	{
		if(index == n)
		{
			solve++;
			return;
		}

		while(i < 4)
		{
			buffer[index] = dnaSeq[i++];
			c = cmpBases(buffer[index], sequence[index]);
			btMutations(index + 1, k + c, it);
		}
	}
	else return;
}

void printMutations(int index, int k, int it)
{
    int c;
	int i = it;
	if(k <= m)
	{
		if(index == n)
		{
			buffer[index] = '\0';
			printf("%s\n", buffer);
			return;
		}

		while(i < 4)
		{
			buffer[index] = dnaSeq[i++];
			c = cmpBases(buffer[index], sequence[index]);
			printMutations(index + 1, k + c, it);
		}
	}
	else return;
}

int main()
{
	scanf("%d", &t);
	while(1)
	{
		if(t-- == 0)
		    break;
		scanf("%d %d", &n, &m);
		scanf("%s", sequence);
		solve = 0;
		btMutations(0, 0, 0);
		printf("%d\n", solve);
		printMutations(0, 0, 0);
	}
	return 0;
}
