#include <vector>
#include <bitset>

int P, M;

using namespace std;
#define MAX_PRIMI 4000000
#define MAX_PACC 300000
bitset<MAX_PRIMI> not_primo;
vector<int> primi;

int fattori[MAX_PRIMI];

void crivello()
{
    primi.push_back(2);
    for(int i = 4; i < MAX_PRIMI; i+=2)
        not_primo[i] = true;
    for(int i = 3; i < MAX_PRIMI; i+=2)
        if(!not_primo[i]) {
            primi.push_back(i);
            for(int j = 2*i; j < MAX_PRIMI; j+=i)
                not_primo[j] = true;
        }
}

void inizializza(int P, int M) {
    // Salviamo P e M in due variabili globali.
    ::P = P;
    ::M = M;
    crivello();
}

int controlla(int checksum) {
    int checksum_orig = checksum;
    vector<int> trovati;
    for(int i = 0; checksum / primi[i] > 0; i++) {
        if(checksum % primi[i] == 0) {
            trovati.push_back(primi[i]);
            if(fattori[primi[i]]) return fattori[primi[i]];

            while(checksum % primi[i] == 0)
                checksum /= primi[i];
        }
    }
    for(int i: trovati)
        fattori[i] = checksum_orig;
    return 0;
}
