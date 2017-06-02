#include <bits/stdc++.h>

using namespace std;

#define MAX_N 200000
#define MAX_C 10000000
long long fenwick[MAX_C];
int nums[MAX_N];

int N;

void update(int idx) {
   idx++;
   do ++fenwick[idx]; while((idx += (idx & -idx)) <= MAX_C);
}
long long query(int idx) {
    idx++; int ris = 0;
    do ris += fenwick[idx]; while((idx -= (idx & -idx)));
    return ris;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", nums + i);

    int min_i = N-1;
    long long ris = 0;
    for(int i = N-1; i >= 0; i--)
    {
        update(nums[i]);
        if(nums[min_i] > nums[i])
            min_i = i;

        ris += query(nums[i]) - query(nums[min_i]);
    }

    printf("%lld\n", ris);
}
