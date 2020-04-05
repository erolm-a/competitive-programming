#include <bits/stdc++.h>

using namespace std;

#define FOR(a,b) for(int i = a; i < b; i++)
#define FOR_REV(a,b) for(int i = a; i >= b; i--)

int main()
{
    vector<set<char>> present;
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    FOR(0, n) {
        string in;
        cin >> in;
        present.push_back(set<char>{});
        for(char c: in)
            present[i].insert(c);
    }

    int ris = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(i == j) continue;
            bool possible = true;
            for(char c: present[i])
                if(present[j].find((c)) == present[j].end())
                    possible = false;
            for(char c: present[j])
                if(present[i].find((c)) == present[i].end())
                    possible = false;
            if(possible)
                ris++;
        }
    }
    cout << 2*ris;
}
