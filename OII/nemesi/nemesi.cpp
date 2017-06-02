#include <vector>
#include <set>
#include <stack>
void nuovo_gruppo();
void aggiungi(int bambino);


using namespace std;

#define MAX_N 100000
//vector<int> mono[MAX_N+1];
set<int> bi[MAX_N];
int visitati[MAX_N];
vector<int> g[3]; // 1-based

void dfs(int i)
{
    stack<int> stati;
    stati.push(i);

    // verifica se vi siano nodi adiacenti già visitati;
    // in tal caso memorizza i loro colori in un bitset
    while(!stati.empty())
    {
        int s = stati.top();
        stati.pop();
        if(visitati[s]) continue;
        char bitset_gruppi = 0;
        for(int v: bi[s]) {
            if(visitati[v])
                bitset_gruppi |= (1 << visitati[v]);
            else stati.push(v);
        }
        // prendi il primo gruppo libero disponibile
        if((bitset_gruppi & 2) == 0)
        {
            visitati[s] = 1;
            g[0].push_back(s);
        }
        else if((bitset_gruppi & 4) == 0) {
            visitati[s] = 2;
            g[1].push_back(s);
        }
        else
        {
            visitati[s] = 3;
            g[2].push_back(s);
        }
    }
}

void smista(int N, int nemico[]) {
    for(int i = 0; i < N; i++)
    {
        //mono[i+1].push_back(nemico[i]);
        bi[i].insert(nemico[i]);
        bi[nemico[i]].insert(i);
    }
    for(int i = 0; i < N; i++)
        if(!visitati[i])
            dfs(i);

    nuovo_gruppo();
    for(int i: g[0])
        aggiungi(i);
    nuovo_gruppo();
    for(int i: g[1])
        aggiungi(i);
    if(g[2].size())
    {
        nuovo_gruppo();
        for(int i: g[2])
            aggiungi(i);
    }
}
