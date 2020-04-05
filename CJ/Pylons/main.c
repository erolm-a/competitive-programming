#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

inline bool can_solve(int r, int c, int ar, int ac) {
    return (r != ar) && (c != ac) &&
        (r - c != ar - ac) && (r + c != ar + ac);
}

inline bool can_solve(int r, int c) {
    if(r > c)
        swap(r, c);
    
    if(r == 2)
        return c > 4;
        
    if (r == 3)
        return c != 3;
        
    return true;
}

#define CYCLES_PER_ATTEMPT 100

vector<pii> solve(int R, int C) {
    vector<vector<bool>> there;
    vector<pii> sol;
    
    if(!can_solve(R, C))
        return {};
    
    while(true) {
        sol.clear();
        there.clear();
        there.resize(R);
        for(int i = 0; i < R; i++)
            there[i].resize(C);
    
        int counter = 0;
        for(int i = 0; i < CYCLES_PER_ATTEMPT;) {
            if(counter == R * C)
                return sol;
            int new_r = rand() % R, new_c = rand() % C;
            if(sol.empty()) {
                sol.emplace_back(new_r, new_c);
                there[new_r][new_c] = true;
                i = 0;
                counter++;
            }
            else {
                int old_r = sol.back().first;
                int old_c = sol.back().second;
                if(!there[new_r][new_c] &&
                    can_solve(old_r, old_c, new_r, new_c)) {
                        
                    sol.emplace_back(new_r, new_c);
                    there[new_r][new_c] = true;
                    i = 0;
                    counter++;
                }
                else i++;
            }
        }
    }
}

int main() {
    srand((unsigned)time(nullptr));
    
    int tcs;
    cin >> tcs;
    
    for(int tc = 1; tc <= tcs; tc++) {
        int R, C;
        cin >> R >> C;
        
        auto solution = solve(R, C);
        
        cout << "Case #" << tc << ": ";
        if(solution.size() == 0)
            cout << "IMPOSSIBLE\n";
        else {
            cout << "POSSIBLE\n";
            for(pii p: solution)
                cout << p.first + 1 << ' ' << p.second + 1<< '\n';
        }
    }
}
