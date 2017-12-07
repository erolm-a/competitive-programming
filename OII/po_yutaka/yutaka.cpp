#define MAX_N 1000001
#define MODULO 1000000007

#include <utility>
#include <algorithm>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
ll DP[MAX_N];
pii minimi[MAX_N];
static int N;

int cur_minimo = MAX_N;

// per lo 0
ll sums[MAX_N];

ll get_somma(int a)
{
    if(cur_minimo == N) return sums[a] + 1;
    return (sums[a] - sums[cur_minimo+1] + MODULO) % MODULO;
}


int taglia(int N, int t[]) {
    :: N = N;
    for(int i = 0; i <= MAX_N; i++)
        minimi[i] = {MAX_N, MAX_N};

    DP[N-1] = 1;
    minimi[t[N-1]].first = N-1;
    sums[N-1] = 1;
    cur_minimo = N;

    for(int i = N-2; i >= 0; i--)
    {
        // somma pregressa fino al prossimo minimo
        minimi[t[i]].second = minimi[t[i]].first;
        minimi[t[i]].first = i;
        cur_minimo = min(cur_minimo, minimi[t[i]].second);
        if(t[i] != t[i+1])
            DP[i] = get_somma(i+1);
        else
            DP[i] = DP[i+1];

        // fine
        sums[i] = (sums[i+1] + DP[i]) % MODULO;
    }

    return DP[0] % MODULO;
}
