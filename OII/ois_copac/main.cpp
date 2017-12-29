#include <bits/stdc++.h>

using namespace std;

// v, size
#define MAX_N 100001
vector<int> adj[MAX_N];
bitset<MAX_N> visited;
int sz[MAX_N];
int parent[MAX_N];

void dfs(int a) {
    sz[a] = 1;
    visited[a] = true;
    for(int i: adj[a])
        if(!visited[i]) {
            parent[i] = a;
            dfs(i);
            sz[a] += sz[i];
        }
}

int main()
{
    int N;
    ifstream in("input.txt");
    ofstream of("output.txt");
    in >> N;
    for(int i = 0; i < N-1; i++)
    {
        int a, b;
        in >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);

    vector<int> s;
    for(int i = 1; i <= N; i++) {
        int m1 = 0;
        for(int j: adj[i])
            if(j != parent[i] && j != 0)
                m1 = max(m1, sz[j]);
        if(max(sz[1] - sz[i], m1) <= N/2)
            s.push_back(i);
    }

    sort(s.begin(), s.end());

    for(int i = 0; i < s.size(); i++)
        of << s[i] << '\n';

}
