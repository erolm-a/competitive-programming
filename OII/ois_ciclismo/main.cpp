#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX_N 10000

int N;
int H[MAX_N];
bool processed[MAX_N];
vector<int> graph[MAX_N];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int M;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf(" %d", H + i);

    for(int i = 0; i < M; i++) {
        int da, a;
        scanf(" %d %d", &da, &a);
        graph[da].push_back(a);
        graph[a].push_back(da);
    }
    for(int i = 0; i < N; i++)
        sort(graph[i].begin(), graph[i].end(), [](int a, int b) { return H[a] < H[b];});

    int current = 0, prec = -1;


    while(prec == -1 || (!(graph[current].size() == 1 && graph[current][0] == prec) && !processed[current])) {
        processed[current] = true;
        if(graph[current][0] == prec) {
            prec = current;
            current = graph[current][1];
        }
        else {
            prec = current;
            current = graph[current][0];
        }
    }
    printf("%d\n", current);
}
