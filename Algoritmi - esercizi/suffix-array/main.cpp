#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1000010
char T[MAX_N];
int n;
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int c[MAX_N];

void counting_sort(int k)
{
    int i, sum, maxi = max(300, n);
    memset(c, 0, sizeof c);
    // conto delle frequenze <-> conto cumulativo
    // Nota: il counting sort è effettuato in base al rango... com'è giusto
    // che sia
    for(i = 0; i < n; i++)
        c[i + k < n ? RA[i + k] : 0]++;
    for(i = sum = 0; i < maxi; i++) {
        int t = c[i]; c[i] = sum; sum += t;}
    // counting sort effettivo
    for(i = 0; i < n; i++)
        tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
    for(i = 0; i < n; i++)
        SA[i] = tempSA[i];
}

void constructSA()
{
    int i, k, r;
    for(i = 0; i < n; i++) RA[i] = T[i]; // fase iniziale: il rango è uguale al
                                         // codice ASCII del carattere
    for(i = 0; i < n; i++) SA[i] = i;    // i suffissi sono in ordine di grandezza
    for(k = 1; k < n; k<<=1) {
        counting_sort(k); // ordina in base al rango
        counting_sort(0); // vero counting sort (potrebbe essere necessario)
        tempRA[SA[0]] = r = 0;
        for(i = 1; i < n; i++)
            tempRA[SA[i]] =
                    (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i] + k] == RA[SA[i-1] + k]) ? r : ++r;
        for(int i = 0; i < n; i++)
            RA[i] = tempRA[i];
        if(RA[SA[n-1]] == n-1) break;
     }
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    n = (int)strlen(gets(T));
    T[n++] = '\0';
    constructSA();
    for(int i = 1; i < n; i++)
        cout << SA[i] << ' ';
}
