#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <map>

using namespace std;

void risolvi(vector<vector<int> > &tipi);

int binaria(int rif, size_t inizio, size_t fine, vector<int>& tipo_v);

#define middle(inizio, fine) (fine + inizio) / 2 + ((fine + inizio) % 2)

int N, Q;

// La chiave è il tipo, i valori sono gli indici
#define MAX 100000

pair<int, int> query[MAX];

int main()
{
    vector<vector<int>> tipi(MAX);
    risolvi(tipi);
    return 0;
}

void risolvi(vector<vector<int>> &tipi)
{
    ifstream i_f("input.txt");
    ofstream o_f("output.txt");
    
    i_f >> N >> Q;
    int t, pos;
    for(int i = 0; i < N; i++) {
        i_f >> t;
        tipi[t].push_back(i);
    }
    for(int i = 0; i < Q; i++) {
        i_f >> pos >> t;
        query[i] = {pos, t};
    }
    
    for(int i = 0; i < Q; i++)
        o_f << binaria(query[i].first, 0, tipi[query[i].second].size() - 1, tipi[query[i].second]) << '\n';
}

int binaria(int rif, size_t inizio, size_t fine, vector<int>& tipi)
{
    // rif è oltre gli estremi
    if(rif <= tipi[inizio])
        return tipi[inizio] - rif;
    if(rif >= tipi[fine])
        return rif - tipi[fine];
    
    if(fine - inizio == 1)
        return min(tipi[fine] - rif, rif - tipi[inizio]);
    
    int m = middle(inizio, fine);

    if(tipi[m]> rif)
        return binaria(rif, inizio, m, tipi);
    return binaria(rif, m, fine, tipi);

}
