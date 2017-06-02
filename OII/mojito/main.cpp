#include <bits/stdc++.h>

// soluzione O(n²), fattibile per via dei pochi elementi
// la bfs era troppo seccante da fare
using namespace std;


#define MAX_N 100
pair<int, int> players[MAX_N];
pair<int, int> palla[MAX_N];

int N;
using pii = pair<int, int>;

pii start_mojito;

inline int dist(const pii&a, const pii& b) {return abs(a.first - b.first) + abs(a.second - b.second);}

int nearest_player(const pii& pos) {
    int ris = 0;
    int min_dist = dist(players[ris], pos);

    for(int i = 0; i < N; i++) {
        int dist1 = dist(players[i], pos);
        if(dist1 < min_dist || (dist1 == min_dist && players[i] < players[ris]))
            ris = i, min_dist = dist1;
    }
    return ris;
}

int risolvi()
{
    static bool visited[MAX_N];
    int cur = nearest_player(start_mojito);
    int sol;

    for(sol = 0; !visited[cur]; visited[cur] = true, sol++, cur = nearest_player(palla[cur]))
        ;
    return sol;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%*d %*d %d %d %d", &start_mojito.first, &start_mojito.second, &N);
    for(int i = 0; i < N; i++)
        scanf("%d %d %d %d", &players[i].first, &players[i].second, &palla[i].first, &palla[i].second);

    printf("%d\n", risolvi());
}
