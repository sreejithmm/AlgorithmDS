#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[] = { 1, 2, 3 };
    int i, j;
    int N = 3;
    int Total = 1 << N;
    for (i = 0; i < Total; i++) {
	for (j = 0; j < N; j++) {
	    if ((i >> j) & 1)
		printf("%d ", A[j]);
	}
	printf("\n");
    }
}
