#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;

    array<int, 26> last_idx,max_dists;
    last_idx.fill(-1);
    max_dists.fill(0);

    for(int i = 0; i < s.size(); i++)
    {
        max_dists[s[i]-'a'] = max(max_dists[s[i]-'a'], i - last_idx[s[i]-'a']);
        last_idx[s[i]-'a'] = i;
    }

    int ris = INT_MAX;
    for(int i = 0;i < 26;i++)
    {
        if(last_idx[i] == -1) continue;

        ris = min(ris, max(max_dists[i], (int) s.size() - last_idx[i]));
    }
    cout << ris << '\n';
}
