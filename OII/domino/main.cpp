#include <cstdio>
#include <vector>
#include <bitset>

using namespace std;

using domino = pair<int, int>;

#define MAXN 10
domino dominos[MAXN];
vector<int> adj[7];
bitset<MAXN> selected;

int N;

int num = 0, ris = 0;

// side rappresenta quello a "sinistra", da non usare
void take_domino(int i, bool side)
{
    num++;
    selected[i] = true;
    if(num > ris) ris = num;

    int comp = side ? dominos[i].first : dominos[i].second;
    for(int j: adj[comp]) {
        if(selected[j]) continue;
        if(dominos[j].first == comp)
            take_domino(j, false);
        else take_domino(j, true);
    }

    selected[i] = false;
    num--;
}
void solve()
{
    for(int i = 0; i < N; i++) {
        take_domino(i, false);
        if(dominos[i].first != dominos[i].second)
            take_domino(i, true);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &dominos[i].first, &dominos[i].second);
        adj[dominos[i].first].push_back(i);
        if(dominos[i].first != dominos[i].second)
            adj[dominos[i].second].push_back(i);
    }
    solve();
    printf("%d\n", ris);
}
