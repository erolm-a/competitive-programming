#include <fstream>
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <vector>
#include <set>

using namespace std;

int M, *V;
uint64_t S;

multiset<uint64_t> massimi;

void Inizializza(int n, int m, int* v) {
    M = m, V = v;
    massimi = multiset<uint64_t>(V, V+n);
    for(int i = 0; i < n; i++)
        S += v[i];
}

int Cambia(int p, int v) {
    S += (v - V[p]);
    int old = V[p];
    V[p] = v;

    massimi.erase(massimi.find(static_cast<uint64_t>(old))); // solo uno va eliminato
    massimi.insert(static_cast<uint64_t>(v));

    if(S % M == 0 && *massimi.crbegin() <= S / M)
        return 1;
    return 0;
}

int main(int argc, char* argv[])
{
    (void)argc; (void)argv;
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n, m, q;
    in >> n >> m >> q;
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        in >> tmp;
        v.push_back(tmp);
    }
    Inizializza(n, m, v.data());
    for(int i = 0; i < q; i++)
    {
        int a, b;
        in >> a >> b;
        out << Cambia(a, b) << endl;
    }
    return EXIT_SUCCESS;
}
