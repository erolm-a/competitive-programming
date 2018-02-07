#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100001

/*
 * Approccio O(N)...
 * in realtà possiamo sfruttare il fatto che N - 1 <= M <= 2N - 3 quindi M = O(N);
 * in media, ogni vertice ha grado K = 2M/N (handshaking lemma); di conseguenza, la
 * complessità è nel caso peggiore O(MKlogK); ma K = O(N) / O(N) = O(1)... in effetti in media
 * è lim N->(oo)  2M/N = (nel caso migliore) = lim N -> (oo) 2(N-1) / N = 2
 * e in quello peggiore lim N->(oo) 2M/N = lim N -> (oo) 2(2N - 3)/N = 4
 *
 * quindi, l'algoritmo è O(O(N) * O(1) * log O(1) ) = O(N)
 */

vector<int> adj[MAX_N];
pair<int, int> edges[2*MAX_N+3];

template<typename Int>
Int readInteger () {
    Int result = 0;
    char ch;
    ch = getchar_unlocked();
    while (true) {
        if (ch >= '0' && ch <= '9') break;
        ch = getchar_unlocked();
    }
    result = ch - '0';
    while (true) {
        ch = getchar_unlocked();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    return result;
}
#define readint readInteger<int>

int where(int a, int b) {
    int r = 0;
    for(int i: adj[a])
        if(i != b && binary_search(adj[b].begin(), adj[b].end(), i)) r++;
    return r;
}
int main()
{
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N, M, ris = 0;
    M = readint(); N = readint();
    for(int i = 0; i < M; i++) {
        int a, b;
        a = readint(); b = readint();
        edges[i] = {a,b};
        adj[a].push_back(b); adj[b].push_back(a);
    }
    for(int i = 1; i <= N; i++)
        sort(adj[i].begin(), adj[i].end());


    for(int i = 0; i < M; i++ ) {
        int a, b;
        tie(a, b) = edges[i];
        if(adj[a].size() < adj[b].size())
            ris += where(a,b);
        else ris += where(b,a);
    }

    printf("%d\n", ris/3);
}
