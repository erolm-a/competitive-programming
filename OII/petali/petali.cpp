#include <bits/stdc++.h>
#define MAX_N 8000000
using namespace std;

//bitset<MAX_N+1> crivello;
int idx_lck[MAX_N];
bitset<MAX_N> fatt_lck;
int N;
//void compilacr()
//{
//    for(int i = 2; i <= N; i++)
//        if(!crivello[i])
//            for(int j = 2*i; j <= N; j+=i)
//                crivello[j] = true;
//}

vector<int> fattorizza(int c) {
    vector<int> ris{1};
//    if(crivello[c]) {
        for(int i = 2; i*i <= c; i++)
            if(c % i == 0) {
               ris.push_back(i);
               if(i != c/i)
                    ris.push_back(c/i);
            }
        sort(ris.begin(), ris.end());
//    }
    return ris;
}

int solve(int N, int* S)
{
    ::N = N;
    //compilacr();

    vector<int> fattori{move(fattorizza(N))};

    int ris = 0;
    for(int f = fattori.size()-1; f >= 0; f--) {
        int F = fattori[f];
        if(fatt_lck[F])
            continue;

        bool ok = false;

        for(int i = 0; i < F; i++) {
            if(idx_lck[i] % F == 0 && idx_lck[i] != 0)
                continue;
            int t;
            for(t = F + i; t < N && S[t] == S[i]; t+=F)
                ;
            if (t >= N) ok = true, ris++;
            else idx_lck[i] *= F;
        }
        if(!ok) {
            // fallimento, escludi i divisori
            for(int i = 0; i < f; i++) {
                if(fattori[i] >= F) break;
                if(F % fattori[i] == 0) fatt_lck[fattori[i]] = true;
            }
        }
    }
    return ris;
}
