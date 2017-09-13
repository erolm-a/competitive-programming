#include <bits/stdc++.h>

using namespace std;
#define MAX_N 400001
vector<int> adj[MAX_N];

int N;

int costo[MAX_N];

struct link{
    bool ok;
    int somma; // per la DP
    int current; // se current == 0, allora questo vertice è escluso
    vector<link*> nexts;
} dp[MAX_N][2];

int parent[MAX_N];
int cerca(int v, bool con)
{
    if(dp[v][con].ok)
        goto end; // Ah, i goto!

    // se non sono preso devo prendere il mio vicino, necessariamente.
    if(con == false)
    {
        dp[v][false].current = 0;
        for(int i: adj[v])
            if(parent[v] != i) {
                parent[i] = v;
                dp[v][con].somma += cerca(i, true);
                dp[v][con].nexts.push_back(&dp[i][true]);
            }
    }
    else {
        dp[v][true].current = v;
        dp[v][true].somma = costo[v];
        // dobbiamo decidere se prendere i successivi o no.
        for(int i: adj[v])
            if(parent[v] != i) {
                parent[i] = v;
                if(cerca(i, true) < cerca(i, false)) {
                    dp[v][con].somma += dp[i][true].somma;
                    dp[v][con].nexts.push_back(&dp[i][true]);
                }
                else {
                    dp[v][con].somma += dp[i][false].somma;
                    dp[v][con].nexts.push_back(&dp[i][false]);
                }
            }
    }
    dp[v][con].ok = true;
end:
    return dp[v][con].somma;
}

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

vector<int> sol;
void esplora(link* s)
{
    if(s->current)
        sol.push_back(s->current);
    for(link* i: s->nexts)
        esplora(i);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    N = readInt();
    for(int i = 1; i <= N; i++)
        costo[i] = readInt();

    for(int i = 0; i < N-1; i++)
    {
        int a, b;
        a = readInt(), b = readInt();
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    link* ris;
    if(cerca(1, true) < cerca(1, false))
        ris = &dp[1][true];
    else ris = &dp[1][false];
    esplora(ris);
    printf("%lu\n", sol.size());
    for(int i: sol)
        printf("%d ", i);
}
