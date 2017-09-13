#include <bits/stdc++.h>

using namespace std;

#define MAX_N 2001

bitset<MAX_N> adj_mat [MAX_N];
int loses[MAX_N];
int N;
int n[MAX_N];
int depth[MAX_N];

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

int dfs(int start)
{
    static bitset<MAX_N> visited;
    visited[start] = true;
    int m = depth[start];
    for(int i = 1; i <= N; i++) {
        if(adj_mat[start][i] && !visited[i] && depth[i] < depth[start] + 1)
        {
            depth[i] = depth[start] + 1;
            int r = dfs(i);
            if(m < r)
                n[start] = i, m = r;
        }
    }
    visited[start] = false;
    return m;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    N = readInt();
    for(int i = 0; i < N*(N-1)/2; i++)
    {
        int a, b; a = readInt(), b = readInt();
        adj_mat[a][b] = true;
        loses[b]++;
    }
    int start = min_element(loses + 1, loses + N+1) - loses;

    printf("%d\n", dfs(start));

    for(int p = start; n[p] > 0; p = n[p])
        printf("%d %d\n", p, n[p]);

    return 0;
}
