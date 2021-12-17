#include <stdio.h>

int main()
{
    int N = 0;
    scanf("%d", &N);
    int *A = new int[N * 2];
    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
        A[i + N] = A[i];
        sum += A[i];
    }

    int target_size = sum / 10;
    int count_size = 0;

    for (int i = 0; i < N; i++)
    {
    }

    return 0;
}