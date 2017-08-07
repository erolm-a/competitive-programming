#include <bits/stdc++.h>

#define MAX_N 75001
#define MAX_M 500000

using namespace std;

// Union-find

namespace UF{
    int _parents[MAX_N];
    void join(int i, int p) {_parents[i] = p;}
    int find(int i) {return _parents[i] == i ? i : _parents[i] = find(_parents[_parents[i]]);} // path compression
}

vector<int> adj_list[MAX_N], incoming[MAX_N];
int disc[MAX_N], low[MAX_N];

struct mystack {
    int st[MAX_N];
    int size = 0;
    void push(int a) {st[size++] = a;}
    void pop() {size--;}
    int top() {return st[size-1];}
    bool empty() {return !size;}
} cur_scc;

int cur_disc;
bitset<MAX_N> on_stack;
vector<int> sccs[MAX_N+1];
int num_components;

int N;
void dfs(int v)
{
    disc[v] = low[v] = ++cur_disc;
    on_stack[v] = true;
    cur_scc.push(v);

    for(int w: adj_list[v]) {
        if(disc[w] == 0) {
            dfs(w);
            low[v] = min(low[v], low[w]);
        } else if(on_stack[w])
            low[v] = min(low[v], disc[w]);
    }
    if(disc[v] == low[v]) // è una radice della componente
    {
        //UF::init(v);
        int k;
        do{
            k = cur_scc.top();
            on_stack[k] = false;
            sccs[num_components].push_back(k);
            UF::join(k, v);
            cur_scc.pop();
        }while(k != v && !cur_scc.empty());
        num_components++;
    }
}

inline void tarjan()
{
    for(int i = 1; i <= N; i++)
        if(disc[i] == 0)
            dfs(i);
//    for(int i = 0; i < num_components; i++)
//    {
//        printf("\nComponente connessa rilevata e radicata in: %d: ", sccs[i].back());
//        for(int i: sccs[i])
//            printf("%d ", i);
//    }
}

int paper(int N, int M, int* from, int* to)
{
    ::N = N;
    for(int i = 0; i < M; i++) {
        adj_list[from[i]].push_back(to[i]);
        incoming[to[i]].push_back(from[i]);
    }

    tarjan();
    int ris = 0;
    int found = 0;
    for(int c = 0; c < num_components; c++) {
        if(found > 1) break;
        bool ok = true;
        for(int i: sccs[c]) {
            // verifica per ogni vertice che non vi siano ingressi
            // "non" idonei
            for(int j: incoming[i])
                if(UF::find(j) != UF::find(sccs[c].front())) {
                    ok = false; goto end;
                }
        }
        end:
            if(ok) ris+=sccs[c].size(), found++;
    }
    if(found > 1)
        return 0;
    else return ris;
}
