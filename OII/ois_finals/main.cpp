#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 1000000

struct esame {
    pair<int, int> limiti;
    esame(int T, int U): limiti{T - U, T + U} {}
    bool intersezione(const esame& altro) {return limiti.second < altro.limiti.first;}
};

bool operator<(const esame& a, const esame& b ) { return a.limiti < b.limiti; }

// struttura dati associata
vector<esame> esami;
vector<int> a_destra_di[MAX_N];

void riempi_intersezioni() {
    for(int i = 1; i < N; i++)
        for(int j = 0; j < i; j++)
            if(esami[i].intersezione(esami[j]))
                a_destra_di[i].push_back(j);
}

int dp[MAX_N];

int N;
int main()
{
    ifstream i_f("input.txt");
    ofstream o_f("output.txt");

    i_f >> N;
    for(int i = 0; i < N; i++) {
        int T, U;
        i_f >> T >> U;
        esami.emplace(T, U);
    }
    sort(esami.begin(), esami.end());

}
