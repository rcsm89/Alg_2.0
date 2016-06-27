#include <stdio.h>
#include <stdlib.h>

char sequence[20];
char buffer[20];
char dnaSeq[5] = "ACGT";
int t, n, m, solve;

void btMutations(int index, int k, int it)
{
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
			btMutations(index + 1, k + (buffer[index] != sequence[index]), it);
			// solve++;
		}
	}
	else return;
}

void printMutations(int index, int k, int it)
{
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
			printMutations(index + 1, k + (buffer[index] != sequence[index]), it);
		}
	}
	else return;
}

int main()
{
	scanf("%d", &t);
	while(1)
	{
		if(t == 0) break;

		scanf("%d %d", &n, &m);
		scanf("%s", sequence);
		solve = 0;
		btMutations(0, 0, 0);
		printf("%d\n", solve);
		printMutations(0, 0, 0);

		t--;
	}
	return 0;
}

