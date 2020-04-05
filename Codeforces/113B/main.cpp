#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pll = pair<long long, long long>;
using pii = pair<int, int>;


#define MAX_N 2001
#define MOD 29996224275833ll

ll compute_hash(string& x) {
    ll hash = 0;
    for(char ch: x)
        hash = ((hash * 26) % MOD + (ch - 'a' + 1)) % MOD;
    return hash;
}

ll hashes[MAX_N][MAX_N];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b, c;

    cin >> a >> b >> c;

    ll b_hash = compute_hash(b),
       c_hash = compute_hash(c);

    //cout << b_hash << endl << c_hash << endl;
    for(int i = 0; i < a.size(); i++ )
        for(int j = i; j < a.size(); j++ )
            hashes[i][j] = ((j > 0 ? (hashes[i][j-1] * 26) % MOD : 0) + (a[j] - 'a' + 1)) % MOD;

    int res = 0;

    unordered_set<ll> diffs;
    for(int i = 0; i < a.size() - b.size(); i++)
        if(hashes[i][i + b.size() - 1] == b_hash) {

            for(int j = i; j < a.size() - c.size() + 1; j++)
                if(hashes[j][j + c.size() - 1] == c_hash)
                {
                    ll cur_hash = hashes[i][j + c.size() - 1];
                    auto it = diffs.find(cur_hash);
                    if (it == diffs.end()) {
                        res++;
                        diffs.insert(cur_hash);

                    }
                }
        }

    cout << res << endl;

}
