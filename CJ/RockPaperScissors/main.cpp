#include <bits/stdc++.h>

using namespace std;

vector<string> programs;
int N;

string solve() {
    string sol;
    vector<bool> knockout(N);
    vector<int> rs, ps, ss;

    for(int i = 0; ; i++) {
        rs.clear();
        ps.clear();
        ss.clear();

        for(int j = 0; j < N; j++) {
            if (knockout[j])
                continue;
            int prog_size = programs[j].size();
            switch(programs[j][i % prog_size]) {
                case 'R':
                    rs.push_back(j);
                break;
                case 'P':
                    ps.push_back(j);
                break;
                case 'S':
                    ss.push_back(j);
                break;
            }
        }
        if(rs.empty() && ps.empty() && ss.empty())
            return sol;
        if(rs.size() && ps.size() && ss.size()) {
            return "IMPOSSIBLE";
        }
        else if(rs.size() && ps.size()) {
            sol.push_back('P');
            for(int i: rs)
                knockout[i] = true;
        }
        else if(rs.size() > 0 && ss.size()) {
            sol.push_back('R');
            for(int i: ss)
                knockout[i] = true;
        }
        else if(ss.size() && ps.size()) {
            sol.push_back('S');
            for(int i: ps)
                knockout[i] = true;
        }
        else if(rs.size()) {
            sol.push_back('P');
            for(int i: rs)
                knockout[i] = true;
        }
        else if(ss.size()) {
            sol.push_back('R');
            for(int i: ss)
                knockout[i] = true;
        }
        else if(ps.size()) {
            sol.push_back('S');
            for(int i: ps)
                knockout[i] = true;
        }
    }
}
int main()
{
    int tcs;
    cin >> tcs;

    for(int tc = 1; tc <= tcs; tc++) {
        cin >> N;
        programs.clear();
        programs.resize(N);
        for(int i = 0; i < N; i++)
            cin >> programs[i];

        cout << "Case #" << tc << ": " << solve() << '\n';
    }

}
