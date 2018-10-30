#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1001
using ll = long long;
ll coeff[MAX_N][MAX_N];


int N, K;

void get_binom() {
    coeff[1][0] = coeff[1][1] = 1;
    for(int n = 2; n <= N; n++)
    {
        coeff[n][0] = coeff[n][n] = 1;
        for(int k = 1; k < n; k++)
            coeff[n][k] = coeff[n-1][k-1] + coeff[n-1][k];
    }
}

int P[] = {1, 2, 9};
int main()
{
    cin >> N >> K;
    get_binom();

    ll sol = 1;
    for(int i = 2; i <= K; i++)
        sol += coeff[N][N-i]*P[i-2];
    cout << sol << '\n';
}
