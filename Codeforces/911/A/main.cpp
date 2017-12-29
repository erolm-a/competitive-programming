#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, min_elem = INT_MAX, last_i, diff = INT_MAX, n;
    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> n;
        if(n < min_elem)
            min_elem = n, last_i = i;
        else if(n == min_elem) diff = min(diff, i - last_i), last_i = i;
    }
    cout << diff << '\n';
}
