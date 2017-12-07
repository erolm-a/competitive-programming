#include <bits/stdc++.h>

using namespace std;

#define vll array<u_int64_t, 4>
#define MAX_N 1000
#define MAX_M 5000
#define MAX_K 75

unsigned long long memo[MAX_N][MAX_K];
vector<vll> adj[MAX_N];

namespace mine {
    int N, S, E, K, T;
}

#define init_memo() fill(memo[0], memo[mine::N], mine::T+1); \
    fill(memo[mine::S], memo[mine::S] + MAX_K, 0)

#define cur_t static_cast<u_int64_t>(p[0])
#define pos static_cast<u_int64_t>(p[1])
#define cur_k static_cast<u_int64_t>(p[2])


bool dijkstra_bin(int X) {
    init_memo();

    priority_queue<vll, vector<vll>, greater<vll>> stati;
    stati.push({0ull, static_cast<u_int64_t>(mine::S), 0ull});

    while(!stati.empty()) {
        auto p = stati.top();
        stati.pop();

        if(pos == mine::E && cur_t < mine::T)
            return true;
        for(auto i: adj[pos]) {
            if(cur_k < mine::K && cur_t + i[2] < memo[i[0]][cur_k + 1]) {
                memo[i[0]][cur_k + 1] = cur_t + i[2];
                stati.push({memo[i[0]][cur_k + 1], i[0], cur_k + 1});
            }
            if(i[3] <= X && cur_t + i[1] < memo[i[0]][cur_k]) {
                memo[i[0]][cur_k] = cur_t + i[1];
                stati.push({memo[i[0]][cur_k], i[0], cur_k});
            }
        }
        if(stati.empty())
            break;
    }

    return false;
}


int avoid_volunteers(int subtask, int N, int M, int K, int S, int E, int T,
                        int A[], int B[], int W[], int P[], int V[]) {

    mine::N = N;
    mine::S = S;
    mine::E = E;
    mine::K = K;
    mine::T = T;

    vector<int> operatrici(V, V + M);
    sort(operatrici.begin(), operatrici.end());

    for(int i = 0; i < M; i++) {
        adj[A[i]].push_back({B[i], W[i], P[i], V[i]});
        adj[B[i]].push_back({A[i], W[i], P[i], V[i]});
    }

    int l = 0, r = operatrici.size()-1;

    if(!dijkstra_bin(operatrici[r])) return -1;
    else if(dijkstra_bin(operatrici[l])) return operatrici[0];

    while(r - l > 1)
    {
        int m = (l + r + 1)/2;
        bool success = dijkstra_bin(operatrici[m]);
        if(success)
            r = m;
        else
            l = m;
    }
    return operatrici[r];
}
