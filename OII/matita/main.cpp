#include <bits/stdc++.h>

#define MAX_N 100000
using namespace std;
bitset<MAX_N+1> visited;
unordered_set<int> adj_list[MAX_N+1];
// ma quindi set >> unordered_set, perché O(1) dell'hash table nasconde
// un grosso fattore costante?
list<int> res;
int N, M, A, B;

int bfs_p[MAX_N + 1];
vector<int> tree;
vector<int> subpath;

// Hierholzer + un lemma mio

void bfs()
{
    queue<int> q;
    q.push(B);
    visited[B] = true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        if(u == A) break;
        for(int i: adj_list[u])
            if(!visited[i]) {
                visited[i] = true;
                bfs_p[i] = u;
                q.push(i);
            }
    }
    for(int i = A; i != B; i = bfs_p[i])
        tree.push_back(i);
    tree.push_back(B);
}

void ciclo(int start_v)
{
    int cur = start_v;
    do {
        auto it = adj_list[cur].begin();
        int temp = cur;
        cur = *it;
        adj_list[temp].erase(it);
        adj_list[cur].erase(temp);
        it = adj_list[cur].find(temp);
        subpath.push_back(cur);
    }
    while(cur != start_v);
}

void eulerian_path()
{
    bfs();
    int start_v = 0;
    for(int i = 0; i < tree.size() - 1; i++)
        adj_list[tree[i]].erase(tree[i+1]), adj_list[tree[i+1]].erase(tree[i]);

    for(int i: tree)
        if(adj_list[i].size() % 2 == 0 && adj_list[i].size() > 0) {
            start_v = i;
            break;
        }
    if(start_v == 0) start_v = A;
    res.push_back(start_v);

    ciclo(start_v);
    res.insert(res.end(), subpath.begin(), subpath.end());
    subpath.clear();
    for(auto p = res.begin(); p != res.end(); p++) {
        if(adj_list[*p].size() > 0)
        {
            ciclo(*p);
            auto q= p; q++;
            res.insert(q, subpath.begin(), subpath.end());
            subpath.clear();
        }
    }
    // merging
    int i; auto it = res.begin();
    for(i = 0; i < tree.size() && tree[i] != start_v; i++) {
        it = res.insert(it, tree[i]);
        it++;
    }
    res.insert(res.end(), tree.begin()+i+1, tree.end());
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
        ch = getchar_unlocked();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    N = readInt(), M = readInt(), A = readInt(), B = readInt();
    for(int i = 0; i < M; i++)
    {
        int a = readInt(), b = readInt();
        adj_list[a].insert(b);
        adj_list[b].insert(a);
    }
    eulerian_path();
    auto p = res.begin();
    auto q = p; q++;
    for (;q != res.end(); p++, q++)
        printf("%d %d\n", *p, *q);
    return 0;
}
