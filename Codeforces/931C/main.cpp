#include <bits/stdc++.h>

using namespace std;

// solve ax + by = S, where a + b = n are positive integers
bool solve(int x, int y, int S, int n, int &a, int &b) {
    if(x == y || n == 0) return false;
    int delta = x - y, da = S - y*n, db = x*n - S;
    if(da % delta != 0 || da / delta < 0 || db % delta != 0 || db / delta < 0) return false;
    a = da/delta, b = db/delta; return true;
}

int main()
{
    int N;
    cin >> N;
    map<int, int> nums;
    for(int i = 0; i < N; i++) {
        int k;
        cin >> k; nums[k]++;
    }

    int min_i = nums.begin()->first;
    int med_i = min_i + 1, max_i = min_i + 2;

    if(!nums[max_i]) // non posso fare altro
    {
        cout << 0 << endl;
        for(auto p: nums)
            while(p.second--)
                cout << p.first << ' ';
        cout << endl;
    }
    else {
        int best_med, best_max, best_m, best_diff = 0;
        int S = min_i*nums[min_i] + med_i*nums[med_i] + max_i*nums[max_i];
        for(int m = 0; m <= N; m++) {
            if(m == min_i) continue;
            int new_med, new_max;

            if(solve(med_i, max_i, (S - m*min_i), N - m, new_med, new_max)) {
                int diff = abs(m - nums[min_i]) + abs(new_med - nums[med_i]) + abs(new_max - nums[max_i]);
                diff /= 2;
                if(best_diff < diff) best_m = m,best_med = new_med, best_max = new_max, best_diff = diff;
            }
        }
        cout << N - best_diff << endl;

        while(best_m--)
            cout << min_i << ' ';
        while(best_med--)
            cout << med_i << ' ';
        while(best_max--)
            cout << max_i << ' ';
        cout << endl;
    }
}
