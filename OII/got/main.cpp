#include <algorithm>

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static FILE *fin, *fout;
static int subtask, N, M, K, S, E, T;
static int *A, *B, *W, *P, *V;

int avoid_volunteers(int, int, int, int, int, int, int, int[], int[], int[], int[], int[]);

int main() {
    fin = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");

    assert(fscanf(fin, "%d%d%d%d%d%d%d", &subtask, &N, &M, &K, &S, &E, &T) == 7);

    A = (int *)malloc(M * sizeof(int));
    B = (int *)malloc(M * sizeof(int));
    W = (int *)malloc(M * sizeof(int));
    P = (int *)malloc(M * sizeof(int));
    V = (int *)malloc(M * sizeof(int));

    for (int i = 0; i < M; i++)
        assert(fscanf(fin, "%d%d%d%d%d", A + i, B + i, W + i, P + i, V + i) == 5);

    fprintf(fout, "%d\n", avoid_volunteers(subtask, N, M, K, S, E, T, A, B, W, P, V));

    fclose(fin);
    fclose(fout);

    return EXIT_SUCCESS;
}




#include <bits/stdc++.h>

using namespace std;


#define vll vector<u_int64_t>
#define MAX_N 1000
#define MAX_M 5000
#define MAX_K 75

unsigned long long memo[MAX_N][MAX_K];
vector<vll> adj[MAX_N];


#define init_memo() fill(memo[0], memo[N], T+1); \
    fill(memo[S], memo[S] + MAX_K, 0)

#define cur_t static_cast<u_int64_t>(p[0])
#define pos static_cast<u_int64_t>(p[1])
#define cur_k static_cast<u_int64_t>(p[2])


bool dijkstra_bin(int N, int S, int E, int K, int T, int X) {
    init_memo();

    set<vector<u_int64_t>> stati;
    stati.insert({0ull, static_cast<u_int64_t>(S), 0ull});

    for(auto p = *stati.begin(); ; p = *stati.begin()) {
        stati.erase(p);

        if(pos == E && cur_t < T)
            return true;
        for(auto i: adj[pos]) {
            if(cur_k < K && cur_t + i[2] < memo[i[0]][cur_k + 1]) {
                memo[i[0]][cur_k + 1] = cur_t + i[2];
                stati.insert({memo[i[0]][cur_k + 1], i[0], cur_k + 1});
            }
            if(i[3] <= X && cur_t + i[1] < memo[i[0]][cur_k]) {
                memo[i[0]][cur_k] = cur_t + i[1];
                stati.insert({memo[i[0]][cur_k], i[0], cur_k});
            }
        }
        if(stati.empty())
            break;
    }

    return false;
}


int avoid_volunteers(int subtask, int N, int M, int K, int S, int E, int T,
                        int A[], int B[], int W[], int P[], int V[]) {

    set<int> found;
    (void) subtask, N;
    for(int i = 0; i < M; i++) {
        if(found.find(V[i]) == found.end())
            found.insert(V[i]);
    }
    vector<int> operatrici;
    copy(found.begin(), found.end(),
         back_inserter(operatrici));


    for(int i = 0; i < M; i++) {
        adj[A[i]].push_back({B[i], W[i], P[i], V[i]});
        adj[B[i]].push_back({A[i], W[i], P[i], V[i]});
    }

    int l = 0, r = operatrici.size() - 1, sol = -1;

    if(!dijkstra_bin(N, S, E, K, T, operatrici[operatrici.size()-1])) return -1;
    else if(dijkstra_bin(N, S, E, K, T, operatrici[0])) return operatrici[0];

    while(l <= r) {
        int m = (l+r)/2;
        bool success = dijkstra_bin(N, S, E, K, T, operatrici[m]);
        if(!success && dijkstra_bin(N, S, E, K, T, operatrici[m+1])) {
            sol = m+1; l = r+1;
        }
        else if(success) r = m-1;
        else l = m + 1;
    }

    return operatrici[sol];
}
