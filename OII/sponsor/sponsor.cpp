#include <bits/stdc++.h>

#define MAX_N 10001

using namespace std;
bitset<MAX_N> adjs[MAX_N];
int nums[MAX_N];

int solve(int N, int M, int* Q, int** sponsors, int* A, int* B)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < Q[i]; j++) {
            adjs[sponsors[i][j]][i] = true;
            nums[sponsors[i][j]]++;
        }
    }
    for(int i = 1; i < M; i++) {
        if(nums[i] <= 1) continue;
        for(int j = i+1; j <= M; j++)
            if(nums[j] > 0) {
                bitset<MAX_N> s = adjs[i] & adjs[j];
                if(s != 0 && s != (nums[i] < nums[j] ? adjs[i] : adjs[j])) {
                    *A = i, *B = j;
                    return 0;
                }
            }
    }
    return 1;
}
