#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 10000
int N;
vector<int> grafo[MAX_N];
int B[MAX_N];

int dfs(int p) {
    int sol = B[p];
    int figli = 0;
    for(auto i: grafo[p])
        figli += dfs(i);
    return max(sol, figli);
}

int main()
{
    FILE* fr = fopen("input.txt", "r");
    FILE *fw = fopen("output.txt", "w");

    fscanf(fr, "%d", &N);
    fscanf(fr, "%d %*d", B);

    for(int i = 1; i < N; i++) {
        int capo;
        fscanf(fr, "%d %d", B + i, &capo);
        grafo[capo].push_back(i);
    }

    fprintf(fw, "%d\n", dfs(0));
    return 0;
}
