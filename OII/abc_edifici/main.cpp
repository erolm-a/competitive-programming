#include <algorithm>
#include <set>
#include <climits>
#include <cstdio>
#include <utility>
#include <vector>

#define MAX_N 5000
#define MAX_K 6

int min_distance[MAX_N+1][MAX_N+1];
int perm[MAX_K];
bool is_sede[MAX_N+1];


int N, K;

using namespace std;
typedef pair<int, int> pii;
vector<pii> graph[MAX_N+1];

void dijkstra(int source) {
   set<pii> stati;
   pii p;

   fill(min_distance[source] + 1, min_distance[source] + N + 1, INT_MAX);
   stati.insert(make_pair(0, source));
   min_distance[source][source] = 0;
   while(!stati.empty()) {
       p = *stati.begin();
       stati.erase(stati.begin());
       for(auto i: graph[p.second]) {
           if(i.first + p.first < min_distance[source][i.second]) {
               stati.erase(make_pair(min_distance[source][i.second], i.second));
               min_distance[source][i.second] = min_distance[i.second][source] = i.first + p.first;
               stati.insert(make_pair(min_distance[source][i.second], i.second));
           }
       }
   }
}

int permuta() {
    sort(perm, perm + K);

    for(int i = 0; i < K; i++)
        dijkstra(perm[i]);

    int minimum = INT_MAX;
    do {
        int totale = 0;
        for(int i = 0; i < K-1; i++)
            totale += min_distance[perm[i]][perm[i+1]];
        for(int i = 1; i <= N; i++)
            if(!is_sede[i]) {
                minimum = min(minimum, totale + min_distance[i][perm[0]] + min_distance[i][perm[K-1]]);
            }

    }while(next_permutation(perm, perm+K));

    return minimum;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int M;
    scanf("%d %d %d", &N, &M, &K);

    for(int i = 0; i < K; i++) {
        scanf(" %d", &perm[i]);
        is_sede[perm[i]] = true;
    }


    int a, b, p;
    for(int i = 0; i < M; i++) {
        scanf("%d %d %d", &a, &b, &p);
        graph[a].push_back(make_pair(p, b));
        graph[b].push_back(make_pair(p, a));
    }


    printf("%d\n", permuta());

    return 0;
}
