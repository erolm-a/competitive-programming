#include <fstream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

#define MAX_N 10000

int lcp(string&a, string& b) {
    int cont = 0;
    for(int i = 0; i < min(a.size(), b.size()); i++)
        if(a[i] == b[i])
            cont++;
    return cont;
}

int main()
{
    ifstream in("input.txt");
    ofstream of("output.txt");

    int N, T;

    vector<string> parole;
    in >> N >> T;
    parole.resize(N);

    vector<pair<string, string> > tomi;
    tomi.resize(N/T);
    for(int i = 0; i < N; i++)
        in >> parole[i];

    for(int i = 0; i < )
}
