#include <bits/stdc++.h>

#define MAX_N 10000
int dp[MAX_N];
using namespace std;

int N, *freccia;

#define dx 0
#define sx 1
int get(int begin)
{
    if(begin >= N) return 0;
    if(dp[begin] >= 0) return dp[begin];
    int m = std::numeric_limits<int>::max();

    int left = 0, right = (freccia[begin+1] == dx);
    for(int l = begin; l - begin < N - l; l++)
    {
        left += (freccia[l] != dx);
        // supponiamo che right sia stato compilato prima
        if(l > begin) right = right - (freccia[l] == dx) +
                    (freccia[2*l-begin] == dx) +
                    (freccia[2*l-begin+1] == dx);
        m = min(m, left + right + get(2*l-begin + 2));
    }
    return dp[begin] = m;

}

int Gira(int N, int* freccia)
{
    fill(dp, dp + N, -1);
    ::N = N, ::freccia = freccia;

    return get(0);
}
