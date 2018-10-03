#include <bits/stdc++.h>

using namespace std;

#define MAX_N 50

vector<int> nums;
bitset<2*MAX_N> chosen;
int N;

int get_diff()
{
    int diffs = 0;
    for(int i = 0; i < 2*N-1;)
        if(!chosen[i]) {
            if(chosen[i+1]) {
                if(i+2 >= 2*N) break;
                diffs += abs(nums[i] - nums[i+2]);
            }
            else diffs += abs(nums[i] - nums[i+1]);
            i+=2;
        }
        else i++;

    return diffs;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n; cin >> N;
    for(int i = 0; i < 2*N; i++) {
        cin >> n;
        nums.push_back(n);
    }

    sort(nums.begin(), nums.begin()+2*N);

    int res = numeric_limits<int>::max();
    for(int i = 0; i < 2*MAX_N - 1; i++)
        for(int j = i+1; j < 2*MAX_N; j++) {
            chosen[i] = chosen[j] = true;
            res = min(res, get_diff());
            chosen[i] = chosen[j] = false;
        }

    cout << res << '\n';
    return 0;
}
