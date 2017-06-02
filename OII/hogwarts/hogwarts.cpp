#include <vector>
#include <bitset>

#define MAX_N 500000
#define MAX_T 20

struct arco {
    int inizio, fine, nodo;
};

using namespace std;
vector<arco> grafo[MAX_N];
vector<int> tempi[MAX_T]; // dai, risparmiamo 8 MiB!
int visitati[MAX_N];

int raggiungi(int N, int M, int A[], int B[], int inizio[], int fine[])
{
    int fine_tempo = 0;
    for(int i = 0; i < M; i++) {
        grafo[A[i]].push_back(arco{inizio[i], fine[i], B[i]});
        grafo[B[i]].push_back(arco{inizio[i], fine[i], A[i]});
        fine_tempo = max(fine_tempo, fine[i]);
    }
    fill(visitati, visitati + N, MAX_T);

    tempi[0].push_back(0);
    visitati[0] = 0;

    for(int i = 0; i < fine_tempo; i++)
        for(int j: tempi[i])
        {
            if(j == N-1) return i;
            for(arco& v: grafo[j])
                if(visitati[v.nodo] > i && v.fine > i) {
                    visitati[v.nodo] = v.inizio + 1;
                    tempi[max(v.inizio, i) + 1].push_back(v.nodo);
                }
        }
    return -1;
}
