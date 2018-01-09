#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long x, y, z, A, B;

    cin >> A >>B >> x >> y >> z;
    long long A2 = 2*x + y;
    long long B2 = y + 3*z;
    cout << max(A2 - A, 0ll) + max(B2 - B, 0ll) << '\n';
}
