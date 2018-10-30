#include <cstdio>
#include <utility>
#include <set>
#include <vector>
#include <climits>

using namespace std;

struct edge {int to; long long peso;};

long long dijkstra(const vector<vector<edge>> & graph, int source, int target) {
    vector<long long> min_distance(graph.size(), LLONG_MAX);
    min_distance[source] = 0;
    set<pair<long long, int> > active_vertices;
    active_vertices.insert({0, source});

    while(!active_vertices.empty()) {
        int where = active_vertices.begin()->second;
        if(where == target) return min_distance[target];
        active_vertices.erase(active_vertices.begin());
        for(auto ed: graph[where]) {
            if(min_distance[ed.to] > min_distance[where] + ed.peso) {
                active_vertices.erase({min_distance[ed.to], ed.to});
                min_distance[ed.to] = min_distance[where] + ed.peso;
                active_vertices.insert({min_distance[ed.to], ed.to});
            }
        }
    }
    return LLONG_MAX;
}

int main()
{
    FILE* in, *out;
    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");

    int N, archi, src, dst;

    fscanf(in, "%d %d %d %d", &N, &archi, &src, &dst);
    vector<vector<edge>> grafo(N+1);

    for(int i = 0; i < archi; i++) {
        int da, a;
        long long peso;
        fscanf(in, " %d %d %lld", &da, &a, &peso);
        grafo[da].push_back({a, peso});
    }

    fprintf(out, "%lld", dijkstra(grafo, src, dst));

    fclose(in);
    fclose(out);
    return 0;
}