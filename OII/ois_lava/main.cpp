#include <cstdio>
#include <algorithm>
#include <queue>
#include <climits>
#include <vector>

using namespace std;

// implementing A*

int N, M;
int heuristic(int X, int Y) {
    if(X == M-1) return (N - 1 - Y)/2;
    if(Y == N-1) return (M - 1 - X)/2;
    if((M - 1) - X > (N - 1) - Y)
        return (M - 1 - X) / 2;
    else
        return (N - 1 - Y) / 2;
}

struct State {
    int weight_t, x, y;
};

#define MAX_N 1000
int min_distance[MAX_N][MAX_N];
char graph[MAX_N][MAX_N];

bool isfree(int x, int y) {
    return (x >= 0 && x < M && y >= 0 && y < N && graph[y][x] != '#');
}


int Astar() {
    fill(min_distance[0], min_distance[MAX_N], INT_MAX);

    min_distance[0][0] = 0;
    auto gr = [](const State& lhs, const State& rhs) {return lhs.weight_t > rhs.weight_t;};

    priority_queue<State, vector<State>, decltype(gr) > stati(gr);

    stati.push(State{heuristic(0, 0), 0, 0});

    while(!stati.empty()) {
        State p = stati.top();
        stati.pop();
        int x = p.x, y = p.y;

        if(x == M - 1 && y == N - 1) return min_distance[M-1][N-1];
        if(isfree(x-1, y) && min_distance[x-1][y] > min_distance[x][y] + 1) {
            min_distance[x-1][y] = min_distance[x][y] + 1;
            stati.push({min_distance[x-1][y] + heuristic(x-1, y), x-1, y});
        }
        if(isfree(x+1, y) && min_distance[x+1][y] > min_distance[x][y] + 1) {
            min_distance[x+1][y] = min_distance[x][y] + 1;
            stati.push({min_distance[x+1][y] + heuristic(x+1, y), x+1, y});
        }
        if(isfree(x, y-1) && min_distance[x][y-1] > min_distance[x][y] + 1) {
            min_distance[x][y-1] = min_distance[x][y] + 1;
            stati.push({min_distance[x][y-1] + heuristic(x, y-1), x, y-1});
        }
        if(isfree(x, y+1) && min_distance[x][y+1] > min_distance[x][y] + 1) {
            min_distance[x][y+1] = min_distance[x][y] + 1;
            stati.push({min_distance[x][y+1] + heuristic(x, y+1), x, y+1});
        }
        if(isfree(x-1, y-1) && min_distance[x-1][y-1] > min_distance[x][y] + 1) {
            min_distance[x-1][y-1] = min_distance[x][y] + 1;
            stati.push({min_distance[x-1][y-1] + heuristic(x-1, y-1), x-1, y-1});
        }
        if(isfree(x-1, y+1) && min_distance[x-1][y+1] > min_distance[x][y] + 1) {
            min_distance[x-1][y+1] = min_distance[x][y] + 1;
            stati.push({min_distance[x-1][y+1] + heuristic(x-1, y+1), x-1, y+1});
        }
        if(isfree(x+1, y-1) && min_distance[x+1][y-1] > min_distance[x][y] + 1) {
            min_distance[x+1][y-1] = min_distance[x][y] + 1;
            stati.push({min_distance[x+1][y-1] + heuristic(x+1, y-1), x+1, y-1});
        }
        if(isfree(x+1, y+1) && min_distance[x+1][y+1] > min_distance[x][y] + 1) {
            min_distance[x+1][y+1] = min_distance[x][y] + 1;
            stati.push({min_distance[x+1][y+1] + heuristic(x+1, y+1), x+1, y+1});
        }
        if(isfree(x-2, y) && min_distance[x-2][y] > min_distance[x][y] + 1) {
            min_distance[x-2][y] = min_distance[x][y] + 1;
            stati.push({min_distance[x-2][y] + heuristic(x-2, y), x-2, y});
        }
        if(isfree(x+2, y) && min_distance[x+2][y] > min_distance[x][y] + 1) {
            min_distance[x+2][y] = min_distance[x][y] + 1;
            stati.push({min_distance[x+2][y] + heuristic(x + 2, y), x+2, y});
        }
        if(isfree(x, y - 2) && min_distance[x][y-2] > min_distance[x][y] + 1) {
            min_distance[x][y-2] = min_distance[x][y] + 1;
            stati.push({min_distance[x][y-2] + heuristic(x, y-2), x, y-2});
        }
        if(isfree(x, y + 2) && min_distance[x][y+2] > min_distance[x][y] + 1) {
            min_distance[x][y+2] = min_distance[x][y] + 1;
            stati.push({min_distance[x][y+2] + heuristic(x, y+2), x, y+2});
        }
    }
    return -1; // never reached
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            scanf(" %c", &graph[i][j]);

    printf("%d\n", Astar());
    return 0;
}
