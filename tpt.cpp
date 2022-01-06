#include <stdio.h>
#include <stdint.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// O(N)
string two_pointer_techinique(const uint32_t N, std::vector<uint64_t> *B, const uint64_t sum)
{
    if (sum % 10 != 0)
    {
        return string("No");
    }
    const uint64_t target_size = sum / 10;

    uint32_t left = 0;
    uint32_t right = 0;

    for (uint32_t i = 0; i < N * 4; i++)
    {

        if (B->at(right) - B->at(left) < target_size && right != N * 2 - 1)
        {
            right += 1;
        }
        else if (B->at(right) - B->at(left) > target_size && left != N * 2 - 1 && left < right)
        {
            left += 1;
        }
        if (left == N * 2 - 1)
        {
            break;
        }

        if (B->at(right) - B->at(left) == target_size)
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
    string decision = two_pointer_techinique(N, &B, sum);
    printf("%s", decision.c_str());

    return 0;
}