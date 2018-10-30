#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1000000
int nums[MAX_N], queries[MAX_N];

int main()
{
    unordered_set<int> different;
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf(" %d", nums + i);
    for(int i = N-1; i>=0; i--) {
        different.insert(nums[i]);
        queries[i] = different.size();
    }

    for(int i = 0; i < M;i++) {
        int x; scanf(" %d", &x);
        printf("%d\n", queries[x-1]);
    }
    return 0;
}
