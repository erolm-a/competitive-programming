#include <cstdio>
#include <algorithm>
#include <cstring>
#include <limits>

using namespace std;

#define MAX_N 200
#define MAX_K 200
#define MAX_T 3600

/* la funzione calc() ha questi parametri:
 * i: l'utente 'i' da cui si considera
 * height: potenza locale del server
 * increases: aumenti effettuati finora
 * increasing: indica se è in corso un upgrade oppure no
 *
 *
 * funzionamento:
 *
 * la funzione restituisce l'area della figura che va dall'utente i a N,
 * usando a partire da quell'utente un'altezza height e avendo usato increases aggiornamenti,
 * con la flag se è possibile interrompersi o è necessario crescere
 *
 * casi limite nel caso si raggiunga la fine:
 *    height è > N: impossibile (non c'è bisogno di usare più di N watt per N utenti)
 *    increases > K: impossibile (troppi upgrade)
 *    i > N: impossibile
 *    i == N: se non sta incrementando, allora ha finito, restituisce 0, altrimenti impossibile
 *
 * regola DP:
 *    se non sta incrementando:
 *      nel caso in cui height > idx (o anche height >= idx + 1, tanto i valori sono interi no?)
 *          posso provare ad aggiungere l'area (t[i+1]-t[i])*height all'area, oppure no
 *              quindi min(qualcosa_di_minimo, area + f(idx+1, height, increases, 0)
 *          posso provare anche ad aumentare, sempre ammesso che height < N
 *              quindi min(qualcosa_di_min, f(i, height, increases, 1)
 *    se invece sto incrementando
 *       posso provare a continuare a incrementare, sempre ammesso che height < N
 *          quindi min(qualcosa_di_min, f(i, height + 1, increases, 1)
 *       oppure posso anche smettere
 *          quindi min(qualcosa_di_min, f(i, height, increases + 1, 0)
 *
 * salvo in una matrice tetradimensionale la quadrupla con il valore minimo
 * */

// idx al massimo ha valore MAX_N
// height al massimo ha valore MAX_N - 1
// increases al massimo ha valore K
// increasing è un bool
int dp[MAX_N+1][MAX_N][MAX_K][2];
int v[MAX_N+1]; // l'ultimo elemento di v (alla posizione N+1) è T
int N, K, T;
#define INFINITY MAX_N * MAX_T + 1; // area massima più 1

int f(int i, int height, int increases, bool increasing) {
    // if(height > N) non necessario, la condizione è assicurata dopo
    if(increases > K)
        return INFINITY;
    if(i == N) {
        if(!increasing) return 0;
        else return INFINITY;
    }
    int &ret = dp[i][height][increases][increasing];
    if(ret != -1) return ret;
    else ret = std::numeric_limits<int>::max();

    if(increasing) {
        if(height < N)
            ret = min(ret, f(i, height + 1, increases, 1));
        ret = min(ret, f(i, height, increases + 1, 0));
    }
    else {
        if(height > i)
            ret = min(ret, (v[i+1]-v[i])*height + f(i+1, height, increases, 0));
        if(height < N)
            ret = min(ret, f(i, height+1, increases, 1));
    }
    return ret;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d %d", &T, &K, &N);
    for(int i = 0; i < N; i++)
        scanf("%d", v+i);
    v[N] = T;
    memset(dp, -1, sizeof(dp));

    printf("%d\n", f(0, 0, 0, 0));
}
