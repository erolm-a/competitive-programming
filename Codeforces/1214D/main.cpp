#include <bits/stdc++.h>

#define REP_plus(i, start,end) for(int i = start; i < end; i++)
#define REP_minus(i, start,end) for(int i = start; i >= end; i--)
using namespace std;

using ll = long long;
using pll = pair<long long, long long>;
using pii = pair<int, int>;

using min_queue_pii = priority_queue<pii, vector<pii>, greater<pii>>;

int n, m;
vector<string> Map;

bool explore() {
    vector<vector<bool>> reachable;
    reachable.resize(n);
    REP_plus(i, 0, n) {
        reachable[i].resize(m);
    }

    reachable[0][0] = true;

    REP_plus(i, 0, n) {
        REP_plus(j, 0, m) {
            if(Map[i][j] == '#') continue;
            if(i > 0)
                reachable[i][j] = reachable[i][j] | reachable[i-1][j];
            if(j > 0)
                reachable[i][j] = reachable[i][j] | reachable[i][j-1];
        }
    }

    return reachable[n-1][m-1];
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    REP_plus(i, 0, max(n, 2)) {
        string str;
        cin >> str;
        Map.push_back(str);
    }


    int sol1 = 0, sol2 = 0;
    if (explore()) {
        if(n > 1 && Map[1][0] == '.')
            sol1++;
        if(m > 1 && Map[0][1] == '.')
            sol1++;
        if(n > 1 && Map[n-2][m-1] == '.')
            sol2++;
        if(m > 1 && Map[n-1][m-2] == '.')
            sol2++;

    }

    cout << min(sol1, sol2);
}
