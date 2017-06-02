#include <cstdio>
#include <utility>

using namespace std;

#define MAX_M 200
#define MAX_N 30
int classifica[MAX_N];
int dove[MAX_N+1];
pair<int, int> query[MAX_M];
int N, M;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%d", classifica + i);
    for(int i = 0; i < M; i++)
        scanf("%d %d", &query[i].first, &query[i].second);

    for(int i = 0; i < N; i++)
        dove[classifica[i]] = i;
    for(int i = 0; i < M; i++) {
        swap(classifica[dove[query[i].first]], classifica[dove[query[i].second]]);
        swap(dove[query[i].first], dove[query[i].second]);
    }

    printf("%d\n", classifica[0]);
}
