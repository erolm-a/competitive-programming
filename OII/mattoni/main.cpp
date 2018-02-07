#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1000001
int sums[MAX_N];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    while(m--) {
        int a, b; scanf("%d %d", &a, &b);
        sums[a-1]++; sums[b]--;
    }
    for(int i = 1; i < n; i++)
        sums[i] += sums[i-1];

    nth_element(sums, sums + n/2, sums + n);
    printf("%d\n", sums[n/2]);
}
