#include <cstdio>
#include <numeric>
#include <algorithm>

using namespace std;

#define MAX_N 100000
int main()
{
    int N, K;
    int V[MAX_N];
    int sum, ris;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++)
        scanf(" %d", V + i);

    ris = sum = accumulate(V, V + K, 0);
    for(int i = K; i < N; i++) {
        sum = sum - V[i - K] + V[i];
        ris = min(ris, sum);
    }


    printf("%d\n", ris);
}
