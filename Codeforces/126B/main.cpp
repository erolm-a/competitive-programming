#include <bits/stdc++.h>

using namespace std;

vector<int> z;
string S;

void z_function(const string& s) {
    z.clear();
    z.resize(s.size());
    const int n = (int) s.size();

    for(int i = 1, l = 0, r = 0; i < n; i++) {
        if(i <= r)
            z[i] = min(z[i-l], r - i + 1);
        while(i + z[i] < n && s[i+z[i]] == s[z[i]]) ++z[i];
        if(r < i + z[i] - 1)
            l = i, r = i + z[i] - 1;
    }
}

inline bool test(int m) {
    string s = S.substr(0, m) + '$' + S;
    z_function(s);

    for(int i = m+2; i < s.size()-m; i++)
        if(z[i] == m)
            return true;
    return false;
}

using ull = unsigned long long;
vector<ull> power_of_26, hash_prefix, hash_suffix;
constexpr ull MODULO = 1000000007;

void make_hashes() {
    power_of_26.resize(S.size());
    power_of_26[0] = 1;
    for(int i = 1; i < power_of_26.size(); i++)
        power_of_26[i] = (power_of_26[i-1]*26ull) % MODULO;

    hash_prefix.resize(S.size());
    hash_suffix.resize(S.size());
    hash_prefix[0] = S[0] - 'a';
    for(int i = 1; i < hash_prefix.size(); i++)
        hash_prefix[i] = (26ull*hash_prefix[i-1] + S[i]-'a') % MODULO;

    hash_suffix.back() = S.back()-'a';
    for(int i = S.size()-2; i >= 0; i--)
        hash_suffix[i] = (hash_suffix[i+1] + (power_of_26[S.size()-i-1]*(S[i]-'a'))) % MODULO;
}

int main() {
    cin >> S;

    int l = 1, r = S.size()-1;
    while(r - l > 1) {
        int m = (r+l)/2;
        if(test(m)) l = m;
        else r = m;
    }
    if(!test(l)) {
        cout << "Just a legend" << endl;
        return 0;
    }

    make_hashes();
    for(; l > 0; l--)
        if(hash_prefix[l-1] == hash_suffix[S.size()-l]
                /*&& S.substr(0, l) == S.substr(S.size()-l)*/) {
            cout << S.substr(0, l) << endl;
            return 0;
        }
    cout << "Just a legend" << endl;
}
