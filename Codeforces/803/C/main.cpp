#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

vector<ull> divisors;
void factorize(ull a)
{
    for(ull i = 1; i*i <= a; i++)
        if(a % i == 0) {
            divisors.push_back(i);
            if(i*i != a)
                divisors.push_back(a/i);
        }
}

ull find_gcd(ull todivide, ull limit)
{
    factorize(todivide);
    sort(divisors.begin(), divisors.end());
    for(auto p = divisors.rbegin(); p != divisors.rend(); p++)
        if(todivide/(*p) >= limit)
            return *p;
    return 1; // non dovrebbe succedere vero?
}

#define TO_CONFRONT 1000000
int main()
{
    ull n, k;
    std::ios::sync_with_stdio(false);

    cin >> n >> k;

    if(k > TO_CONFRONT || n < k*(k+1)/2) {
        cout << "-1\n";
        return 0;
    }
    ull gcd = find_gcd(n, k*(k+1)/2);

    ull s = 0;
    for(ull i = 1; i <= k-1; i++)
        cout << ((s += i*gcd), i*gcd) << ' ';
    cout << n - s << '\n';
}
