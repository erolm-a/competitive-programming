#include <bits/stdc++.h>

using namespace std;

#define MAX_V 1000
#define MAX_E 1000

struct flow{
    int source, dest, max_cap, actual_cap;
} edge_list[MAX_E];

struct adj {
    flow* normal, *opposite;
};
vector<adj> adj_list[MAX_V];

adj p[MAX_V];
int maxflow(int s, int t)
{
    fill(p, p + MAX_V, {-1, nullptr});
    int f, mf = 0;
    while(true) {
        // bfs tra s e t
        queue<int> q;
        bitset<MAX_V> vis;
        q.push(s);
        vis[s] = true;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            if(u==t) break;
            for(adj& v: u) {
                if(vis[v.normal->dest] && v.normal->actual_cap > 0) {
                    p[v.normal->dest] = v;
                    vis[v.normal->dest] = true;
                    q.push(v.normal->dest);
                }
            }
        }
        for(int i = t; p[i].opposite != nullptr; i = p[i].opposite->dest;
            if()
        if(f == 0)
            return mf;

    }
}
int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
