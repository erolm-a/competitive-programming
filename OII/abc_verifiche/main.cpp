#include <cstdio>
#include <algorithm>
#include <numeric>

using namespace std;

#define MAX 1000
int studio[3*MAX];
int verifiche[MAX];

int N, T, K;

int calcola()
{
    if(K > T) return -1;

    constexpr int start = 1000;
    fill(studio + start + verifiche[0] - K, studio + start + verifiche[0], 1);

    for(int i = 1; i < N; i++)
    {
        auto begin_idx = studio + start + verifiche[i] - K,
                end_idx = studio + start + verifiche[i];
        if(verifiche[i] - verifiche[i-1] > T)
            fill(begin_idx, end_idx, 1);
        else
        {
            int done = accumulate(studio + start + verifiche[i] - T, end_idx, 0);
            fill(begin_idx + done, end_idx, 1);
        }
    }
    return accumulate(studio, studio + start + verifiche[N-1], 0);
}


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d %d", &N, &T, &K);
    for(int i = 0; i < N; i++) {
        scanf("%d", &verifiche[i]);
    }

    printf("%d\n", calcola());
    return 0;
}
