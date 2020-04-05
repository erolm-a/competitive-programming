#include <bits/stdc++.h>

using namespace std;

#define MAX_N 130
bool adj[MAX_N][MAX_N];

int N;
vector<int> taken;
int max_clique;

void compute() {
    if(taken.size() > max_clique) max_clique = taken.size();
    for(int i = taken.size() ? taken.back()+1 : 0; i < N - (max_clique - taken.size()); i++) {
        bool ok = true;
        for(int j: taken)
            if(!adj[i][j]) {ok = false; break;}
        if(ok) {
            taken.push_back(i);
            compute();
            taken.pop_back();
        }
    }
}

int main()
{
    int tc;
    scanf("%d", &tc);
    vector<int> sols;
    while(tc--) {
        scanf("%d\n", &N);
        taken.clear();
        max_clique = 0;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++){
                char ch;
                scanf(" %c", &ch);
                adj[i][j] = ch - '0';
            }
        compute();
        sols.push_back(max_clique);

    }

    for(int i: sols)
        printf("%d\n", i);
}
