#include <vector>
#include <utility>
#include <set>
#include <cstdio>
#include <climits>

using namespace std;

struct edge {int to, peso;};

int N, A, B;

int dijkstra(const vector<vector<edge>> &graph, int src, int dst) {
    vector<int> min_distance(graph.size(), INT_MAX);
    set<pair<int, int>> active_vertices;
    min_distance[1] = 0;
    active_vertices.insert({0, src});

    while(!active_vertices.empty()) {
        int where = active_vertices.begin()->second;
        if(where == dst)
            return min_distance[dst];
        active_vertices.erase(active_vertices.begin());
        for(auto ed: graph[where])
            if(min_distance[ed.to] > min_distance[where] + ed.peso) {
                active_vertices.erase({min_distance[ed.to], ed.to});
                min_distance[ed.to] = min_distance[where] + ed.peso;
                active_vertices.insert({min_distance[ed.to], ed.to});
            }
    }
    return INT_MAX;
}

int main()
{
    FILE* in, *out;
    int da, a;

    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");

    fscanf(in, "%d %d %d", &N, &A, &B);

    vector<vector<edge>> grafo(N + 1);

    for(int i = 1; i <= A; i++) {
        fscanf(in, " %d %d", &da, &a);
        grafo[da].push_back({a, 0});
        grafo[a].push_back({da, 0});
    }

    for(int i = 1; i <= B; i++) {
        fscanf(in, " %d %d", &da, &a);
        grafo[da].push_back({a, 1});
        grafo[a].push_back({da, 1});
    }

    fprintf(out, "%d\n", dijkstra(grafo, 1, N));

    fclose(in);
    fclose(out);

    return 0;
}
