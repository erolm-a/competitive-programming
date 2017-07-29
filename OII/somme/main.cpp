#include <cstdio>
#include <bitset>
#include <utility>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAX_N 500

pair<long long, long long> dp[MAX_N][MAX_N];
bitset<MAX_N> visited[MAX_N];

int N;
int numbers[MAX_N];

#define int_abs(x) ((x) > 0 ? (x) : -(x))

int readInt () {
    bool minus = false;
    int result = 0;
    char ch;
    ch = getchar_unlocked();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar_unlocked();
    }
    if (ch == '-') minus = true; else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

pair<long long, long long> solve(int begin, int end)
{
    if(visited[begin][end])
        return dp[begin][end];
    visited[begin][end] = true;
    if(end - begin == 1)
        return dp[begin][end] = make_pair(numbers[begin] + numbers[end],
                                          int_abs(numbers[begin] + numbers[end]));

    long long sum = solve(begin, (begin+end)/2).first + solve((begin+end)/2+1, end).first;
    long long t[end - begin];

    for(int i = begin; i < end; i++)
        t[i - begin] = max(int_abs(solve(begin, i).second), int_abs(solve(i+1, end).second));

    long long min_costo = max(int_abs(sum), *min_element(t, t + end - begin));
    return dp[begin][end] = make_pair(sum, min_costo);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    N = readInt();
    for(int i = 0; i < N; i++)
        numbers[i] = readInt();
    for(int i = 0; i < N; i++)
        visited[i][i] = true, dp[i][i] = make_pair(numbers[i],
                                                   0);

    printf("%lld\n", solve(0, N-1).second);
}
