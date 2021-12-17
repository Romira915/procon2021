#include <stdio.h>
#include <stdint.h>
#include <string>

using namespace std;

string standard(const uint32_t N, const uint32_t A[], const uint64_t target_size)
{
    uint64_t count_size = 0;

    for (int i = 0; i < N; i++)
    {
        count_size = 0;
        for (int j = i; j < N * 2; j++)
        {
            count_size += A[j];
            if (count_size == target_size)
            {
                return string("Yes");
            }
            if (count_size > target_size)
            {
                break;
            }
        }
    }

    return string("No");
}

int main()
{
    uint32_t N = 0;

    scanf("%u", &N);

    uint32_t *A = new uint32_t[N * 2];
    uint64_t sum = 0;

    for (int i = 0; i < N; i++)
    {
        scanf("%u", &A[i]);
        A[i + N] = A[i];
        sum += A[i];
    }

    const uint64_t target_size = sum / 10;

    string decision = standard(N, A, target_size);
    printf("%s", decision.c_str());

    delete[] A;

    return 0;
}