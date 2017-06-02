#include <cstdio>
#include <vector>

#define MAX_SOST 2001

using namespace std;
vector<int> dipendenze[MAX_SOST];

int dfs(int i) {
    // già presente nell'acqua
    if(dipendenze[i].size() == 0)
        return -1;
    // già presente nell'acqua
    else if(dipendenze[i][0] == -1)
        return 0;

    int somma = 1, c;
    for(auto j: dipendenze[i]) {
        if((c = dfs(j)) == -1)
            return -1;
        somma += c;
    }
    dipendenze[i][0] = -1;
    return somma;
}


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int K, N;
    scanf("%d %d", &K, &N);
    while(K--)
    {
        int c;
        scanf("%d", &c);
        dipendenze[c].push_back(-1);
    }
    while(N--)
    {
        int s, n, c;
        scanf("%d %d", &s, &n);
        while(n--) {
            scanf("%d", &c);
            dipendenze[s].push_back(c);
        }
    }
    printf("%d\n", dfs(1));
}
