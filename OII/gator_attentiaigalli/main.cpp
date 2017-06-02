#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1000


vector<int> grafo[MAX_N + 1];
int roots[2][MAX_N + 1];
set<pair<int, int>> percorsi_comuni[2];

void bfs(int start) {
    int end = start == 1 ? 2 : 4;
    int* myroot = roots[start/2];

    using state = pair<int, int>;
    queue<int> states;
    for(int j: grafo[start])
    {
        states.push(j);
        myroot[j] = start;
    }

    while(!states.empty())
    {
        int p = states.front();
        states.pop();
        if(p == end)
            break;
        for(int i: grafo[p])
        {
            if(i == myroot[p])
                continue;
            states.push(i);
            myroot[i] = p;
        }
    }

    for(int r = end; r != start; r = myroot[r])
    {
        state a = make_pair(r, myroot[r]);
        if(a.first > a.second) swap(a.first, a.second);
        percorsi_comuni[start/2].insert(a);
    }
}

int calcola() {
    bfs(1);
    bfs(3);

    int cont = 0;
    for(auto& p: percorsi_comuni[0])
        if(percorsi_comuni[1].find(p) != percorsi_comuni[1].end())
            cont++;
    return cont;
}

int main()
{
    FILE* in = fopen("input.txt", "r");
    FILE* out = fopen("output.txt", "w");

    int N;
    fscanf(in, "%d", &N);
    for(int i = 0; i < N-1; i++)
    {
        int a, b;
        fscanf(in, "%d %d", &a, &b);
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    fprintf(out, "%d", calcola());
}
