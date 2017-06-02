#include <bits/stdc++.h>

using namespace std;

#define MAX_N 75000
vector<int> adj_list[MAX_N+1];

bitset<MAX_N> visited;
bitset<MAX_N> tried;

int N;

bool visit(int start) {
    visited.reset();
    queue<int> stati;
    stati.push(start);
    visited[start] = true;
    int count = 1;
    while(!stati.empty())
    {
        int s = stati.front();
        stati.pop();
        for(int i: adj_list[s])
        if(!visited[i]) {
            visited[i] = true;
            count++;
            stati.push(i);
        }
    }
    return count == N;
}

int paper(int N, int M, int* from, int* to)
{
    ::N = N;
    for(int i = 0; i < M; i++)
        adj_list[from[i]].push_back(to[i]);

    for(int i = 1; i <= N; i++)
        if(adj_list[i].size() == 0) tried[i] = true;

    int ris = 0;
    for(int i = 1; i <= N; i++) {
        if(!tried[i]) {
            tried[i] = true;
            visit(i) && ris++;
        }
    }
    return ris;
}
