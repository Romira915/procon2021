#include <stdio.h>
#include <stdint.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// O(N*logN)
string binary_search(const uint32_t N, std::vector<uint64_t> *B, const uint64_t sum)
{
    if (sum % 10 != 0)
    {
        return string("No");
    }
    const uint64_t target_size = sum / 10;

    for (int i = 0; i < N; i++)
    {
        uint64_t t = (u_int64_t)B->at(i) + target_size;
        std::vector<uint64_t>::iterator it = std::lower_bound(B->begin() + i, B->end(), t);
        if (t == *it)
        {
            return string("Yes");
        }
    }

    return string("No");
}

int main()
{
    uint32_t N = 0;

    scanf("%u", &N);

    std::vector<uint32_t> A(N);
    std::vector<uint64_t> B(N * 2);
    uint64_t sum = 0;

    // Step.1 input
    for (uint32_t i = 0; i < N; i++)
    {
        scanf("%u", &A[i]);
        sum += A[i];
        B[i] = sum;
    }

    // Step.2 Make Array B
    for (uint32_t i = 0; i < N; i++)
    {
        B[i + N] = B[i + N - 1] + A[i];
    }

    // Step.3 Search
    string decision = binary_search(N, &B, sum);
    printf("%s", decision.c_str());

    return 0;
}