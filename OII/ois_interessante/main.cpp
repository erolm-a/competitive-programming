#ifdef EVAL
#include <fstream>
#else
#include <iostream>
#endif

using namespace std;

/*
 * Approccio backtracking molto efficiente
 *
 * Backtracking: parto dalla fine provando a impostare i bit a 1 o a 0
 * a seconda delle posizioni len + i, len + 2i, len + 3i
 *
 * Pruning: supponiamo esista un valore minimo di bit da impostare a 1
 * perché esista un conteggio. Allora ci si può fermare quando si nota
 * che è troppo basso (ovvero K è minore del numero minimo di bit da impostare
 * a 1) o troppo alto (K è maggiore del numero massimo di bit imponibili a 0).
 *
 * */

#define MAX_N 2001
int minK[MAX_N];
bool cod[MAX_N];
int len, cont;
bool skip;

void backtrace(int N, int K) {
    if(N == 0) {cont++; return;}
    if(K < minK[N] || K > N - minK[N]) return;

    bool pos[2] = {true, true};
    for(int i = 1; i <= 10 && i <= len/3 ; i++)
        if(cod[len - i] == cod[len - 2*i] && cod[len-2*i] == cod[len-3*i])
            pos[cod[len-i]] = false;

    if(K == 0) pos[1] = false; // ho esaurito i K, non potrei comunque
    if(K == N) pos[0] = false; // ho troppi K, devo usarli

    if(pos[0]) {cod[len++] = 0; backtrace(N-1, K); if(skip && cont) return; len--;}
    if(pos[1]) {cod[len++] = 1; backtrace(N-1, K-1); if(skip && cont) return; len--;}
}

void init(int N, int K) {
    skip = true;
    minK[0] = 0;
    for(int i = 1; i <= N; i++) {
        for(minK[i] = minK[i-1]; cont==0; minK[i]++, len = 0){
            cont = 0;
            backtrace(i, minK[i]);
        }
        minK[i]--;
    }
    cont = 0;
    skip = false;
    backtrace(N, K);
}

int main()
{
    int N, K;
#ifdef EVAL
    ifstream("input.txt") >> N >> K;
#else
    cin >> N >> K;
#endif
    init(N, K);
#ifdef EVAL
    ofstream("output.txt") << cont << endl;
#else
    cout << cont << endl;
#endif


}
