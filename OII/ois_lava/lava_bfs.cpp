#include <cstdio>
#include <algorithm>
#include <queue>
#include <climits>
#include <vector>
#include <bitset>
#include <utility>

using namespace std;


int N, M;

#define MAX_N 1000
bitset<MAX_N> visited[MAX_N];
char graph[MAX_N][MAX_N];

bool isfree(int x, int y) {
    return (x >= 0 && x < M && y >= 0 && y < N && graph[y][x] != '#');
}

struct stato {
    int count, x, y;
};

int BFS() {
    queue<stato> stati;

    stati.push({0, 0, 0});

    while(!stati.empty()) {
        stato p = stati.front();
        stati.pop();
        int x = p.x, y = p.y, count = p.count;

        if(x == M - 1 && y == N - 1) return count;
        if(isfree(x-1, y) && !visited[x-1][y]) {
            visited[x-1].set(y);
            stati.push({count+1, x-1, y});
        }
        if(isfree(x+1, y) && !visited[x+1][y]) {
            visited[x+1].set(y);
            stati.push({count+1, x+1, y});
        }
        if(isfree(x, y-1) && !visited[x-1][y]) {
            visited[x].set(y-1);
            stati.push({count+1, x, y-1});
        }
        if(isfree(x, y+1) && !visited[x][y+1]) {
            visited[x].set(y+1);
            stati.push({count+1, x, y+1});
        }
        if(isfree(x-1, y-1) && !visited[x-1][y-1]) {
            visited[x-1].set(y-1);
            stati.push({count+1, x-1, y-1});
        }
        if(isfree(x-1, y+1) && !visited[x-1][y+1]) {
            visited[x-1].set(y-1);
            stati.push({count+1, x-1, y+1});
        }
        if(isfree(x+1, y-1) && !visited[x+1][y-1]) {
            visited[x+1].set(y-1);
            stati.push({count+1, x+1, y-1});
        }
        if(isfree(x+1, y+1) && !visited[x+1][y+1]) {
            visited[x+1].set(y+1);
            stati.push({count+1, x+1, y+1});
        }
        if(isfree(x+2, y) && !visited[x+2][y]) {
            visited[x+2].set(y);
            stati.push({count+1, x+2, y});
        }
        if(isfree(x-2, y) && !visited[x-2][y]) {
            visited[x-2].set(y);
            stati.push({count+1, x-2, y});
        }
        if(isfree(x, y+2) && !visited[x][y+2]) {
            visited[x].set(y+2);
            stati.push({count+1, x, y+2});
        }
        if(isfree(x, y-2) && !visited[x][y-2]) {
            visited[x].set(y-2);
            stati.push({count+1, x, y-2});
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

    printf("%d\n", BFS());
    return 0;
}
 
