#include <algorithm>
#include <iostream>

using namespace std;

#define MAX_SPACE 1<<18
#define MAX_N 35
using ll = long long;
ll X[MAX_SPACE], Y[MAX_SPACE], N, M, A[MAX_N];

void calc(ll*x, int n, int c)
{
    for(int i = 0; i < (1<<n); i++) {
        ll s = 0;
        for(int j = 0; j < n; j++)
            if(i & (1 << j)) s = (s + A[j+c]) % M;
        x[i] = s;
    }
}

ll solve()
{
    calc(X, N/2, 0);
    calc(Y, N - N/2, N/2);
    int sz_X = 1<<(N/2), sz_Y = 1<<(N-N/2);
    sort(Y, Y+sz_Y);
    ll sol = 0;
    for(int i = 0; i < sz_X; i++)
    {
        int p = lower_bound(Y, Y + sz_Y, M - X[i]-1) - Y;
        if(p == sz_Y || Y[p] != M-X[i]-1) p--;

        sol = max({sol, (X[i]+Y[p]) % M, (X[i] + Y[sz_Y-1])%M});
    }
    return sol;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> A[i];

    cout << solve() << '\n';
}
