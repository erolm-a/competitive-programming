#include <bits/stdc++.h>

using namespace std;

using dp_s = pair<uint16_t, uint8_t>;

template<> struct std::hash<dp_s> {
    size_t operator() (const dp_s& status) const {
        return hash<size_t>()(status.first<< 8ull | status.second);
    }
};

unordered_map<dp_s, int> memo;

#define MAX_LENGTH 10000
int n, m;

vector<int> matrix[16];

int diff_same[16][16], diff_not_same[16][16];

int first_row;

// useful for pruning
int global_answer = 0;
uint16_t exit_case;

int dp(dp_s status) {
    // already found
    if(auto it = memo.find(status); it != memo.end())
        return it->second;

    auto [used, current] = status;
    int diff = INT_MAX;
    // exit case, evaluate the wrapping
    if(used == exit_case) {
        diff = diff_not_same[current][first_row];
        if(diff < global_answer) return memo[status] = 0;
        return memo[status] = diff;
    }

    // enter case
    if(used == 0) {
        for(uint8_t i = 0; i < n; i++) {
            first_row = i;
            memo.clear(); // changing rows invalidates the DP
            if(auto new_status = make_pair(1<<i, i); dp(new_status) >= global_answer)
                // don't waste your time in finding a better way, let bisearch do that!
                return memo[status] = global_answer = dp(new_status);
        }
        return memo[status] = 0; // impossible
    }

    // general case, pick a row
    for(int r = 0; r < n; r++)
        if(int row = 1<<r; !(used & row)) {
            diff = diff_same[r][current];
            if(diff < global_answer) continue; // prune
            used |= row;
            int temp_res = min(diff, dp(make_pair(used, r)));
            if(temp_res >= global_answer)
                return memo[status] = temp_res;
            used ^= row;
        }
    return memo[status] = 0;
}

inline void init() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            diff_same[i][j] = INT_MAX;
            diff_not_same[i][j] = INT_MAX;
            for(int c = 0; c < m; c++) {
                diff_same[i][j] = min(diff_same[i][j], abs(matrix[i][c] - matrix[j][c]));
                if(c < m-1)
                    diff_not_same[i][j] = min(diff_not_same[i][j], abs(matrix[i][c] - matrix[j][c+1]));
            }

        }
    ::exit_case = (1 << n) - 1;
}
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        matrix[i].resize(m);
        for(int j = 0; j < m; j++)
            cin >> matrix[i][j];
    }

    init();

    // avoid worst cases (?)
    // shuffle(matrix, matrix + n, default_random_engine(time(nullptr)));

    int lo, hi;
    for(lo = 0, hi = 1e9; hi - lo > 1;) {
        int mid = (lo + hi) / 2;
        ::global_answer = mid;
        memo.clear();
        int res = dp({});
        if(res) lo = res;
        else hi = mid;
    }
    cout << lo;
}
