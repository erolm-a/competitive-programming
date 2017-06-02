#include <bits/stdc++.h>

using namespace std;

#define MAX_V 15000
int dim[MAX_V];

int N;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", dim + i);
    sort(dim, dim + N);
    int ris = 0;
    for(int i = 0; i < N-2; i++)
        for(int j = i+1; j < N-1; j++)
            ris += dim + N - upper_bound(dim, dim + N, dim[i] + dim[j]);
    printf("%d\n", ris);
}
