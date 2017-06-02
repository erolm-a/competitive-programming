#include <vector>
#include <bitset>

#define MAX_N 100000
using namespace std;
vector<int> adj[MAX_N + 1];
bitset<MAX_N + 1> visited;

void dfs(int u, int& q1, int &q2, int& qa)
{
    visited[u] = true;
    int s = adj[u].size();
    if(s == 1) q1++;
    else if(s == 2) q2++;
    else if(s > 2) qa++;

    for(auto v: adj[u])
        if(!visited[v])
            dfs(v, q1, q2, qa);
}

void Analizza(int N, int M, int A[], int B[], int T[])
{
    for(int i = 0; i < M; i++) {
        adj[A[i]].push_back(B[i]);
        adj[B[i]].push_back(A[i]);
    }

    for(int i = 1; i <= N; i++)
        if(!visited[i]) {
            int q1 = 0, q2 = 0, qa = 0;
            dfs(i, q1, q2, qa);

            if(q1 == 2 && qa == 0)
                T[0]++;
            else if(q1 == 0 && q2 > 0 && qa == 0)
                T[1]++;
            else if(q2 == 0 && qa == 1)
                T[2]++;
        }
}
