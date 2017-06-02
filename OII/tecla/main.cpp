#include <queue>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;


#define MAX_N 30
vector<int> grafo[MAX_N];

struct mypair {
    int a, b;
    bool operator == (const mypair& other) const
    {
        return (other.a == a && other.b == b) ||
                (other.a == b && other.b == a);
    }
};

vector<mypair> soluzione;
int N;
void ciclo()
{
    queue<vector<mypair>> stati;
    for(int i: grafo[0])
        stati.push({mypair{0, i}});

    while(!stati.empty())
    {
        auto s = move(stati.front());
        stati.pop();
        int i = s.back().b;

        if(soluzione.size() > 0 && s.size() > soluzione.size()) continue;

        if(i == 0 && s.size() % 2) {
            soluzione = move(s);
            return;
        }
        for(auto j: grafo[i]) {
            auto idx = find(s.begin(), s.end(), mypair{i, j}) - s.begin();
            if(idx == s.size() || (idx+s.size()) % 2 == 0)
            {
                stati.push(s);
                stati.back().push_back({i, j});
            }
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, M;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    ciclo();
    printf("%d\n", soluzione.size());
    for(int i = 0; i < soluzione.size(); i++)
        printf("%d ", soluzione[i].a);
    printf("0\n");
}
