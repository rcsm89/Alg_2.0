#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int findDigitFromSequenceN(int n, int index)
{
    char str[100];
    int sol;

    sprintf(str, "%d", n);
    sol = str[index-1] - '0';

    return sol;
}

int accumulate(long long *v, int n)


int main()
{
    int T, qtdN;
    long long maxN = 2147483647;
    long long maxLEN = trunc(sqrt(maxN));
    long long i, j, vetA[maxLEN], vetSeq[maxLEN];

    for (i = 1, j = 0; j < maxN; i++)
    {
        vetSeq[i] = log10(i) + 1;
        vetA[i] = vetA[i - 1] + vetSeq[i];
        j += vetA[i];
    }

    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        i = 0;
        while (n > vetA[i])
        {
            n = n - vetA[i];
            i++;
        }

        qtdN = 1;
        while (n > vetSeq[qtdN])
        {
            n = n - vetSeq[qtdN];
            qtdN++;
        }

        printf("%d\n", findDigitFromSequenceN(qtdN, n));
    }
    return 0;
}