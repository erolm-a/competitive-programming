#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
constexpr ull MODULO = 998244353;

string s, lower, upper;

vector<int> z_function(const string&& s) {
    vector<int> z(s.size());
    const auto n = s.size();

    for(int i = 1, r = 0, l = 0; i < n; i++) {
        if(i <= r)
            z[i] = min(z[i-r], r-i+1);
        while(i + z[i] < n && s[z[i]] == s[i+z[i]]) ++z[i];
        if(i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

#define len(i) (n-(i))
int main()
{
    cin >> s >> lower >> upper;

    const auto n = s.size();
    auto z_lower = z_function(lower + '$' + s);
    auto z_upper = z_function(upper + '$' + s);
    auto l_sz = lower.size(), u_sz = upper.size();


    ull comb = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] == '0') continue;
        if(len(i) < lower.size()) comb = (comb + len(i)) % MODULO;
        else
            comb = (comb + lower.size()-1 +
                    (s[i + z_lower[i+l_sz+1]] < lower[z_lower[i+l_sz+1]])) % MODULO;
        if(len(i) >= u_sz) {
            comb = (comb + len(i) - u_sz) % MODULO;
            if(z_upper[i + u_sz + 1] < u_sz)
                comb = (comb + (s[i + z_upper[i + u_sz + 1]] > upper[z_upper[i+u_sz+1]])) % MODULO;
        }
    }

    cout << (MODULO + n*(n+1)/2 - comb) % MODULO << endl;
}
