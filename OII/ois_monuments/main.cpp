#include <bits/stdc++.h>

using namespace std;

#define MAX_K 1000000
int degs[2*MAX_K];

int main()
{
    int N, K, L;
    cin >> N >> K >> L;

    for(int i = 0; i < N; i++) {
        int d;
        cin >> d;
        degs[i] = d;
    }

    sort(degs, degs + N);

    int best = INT_MAX;
    for(int p = 0; p <= K - L; p++) {
        int u1 = upper_bound(degs, degs + N, p + L-1) - lower_bound(degs, degs + N, p);
        int u2 = upper_bound(degs, degs + N, p + L + K-1) - lower_bound(degs, degs + N, p + K);

        best = min(best, u1 + u2);
    }

    cout << best << '\n';
    return 0;
}
