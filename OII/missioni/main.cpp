#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    scanf("%d", &N);
    pair<int, int> missioni[N];

    for(int i = 0; i < N; i++)
        scanf("%d %d", &missioni[i].second, &missioni[i].first);

    priority_queue<int> longest;
    int time = 0, presi = 0;
    for(int i = 0; i < N; i++)
    {
        longest.push(missioni[i].second);
        time += missioni[i].second;
        presi++;
        if(time > missioni[i].first) {
            presi--;
            time -= longest.top();
            longest.pop();
        }
    }
    printf("%d\n", presi);
}
