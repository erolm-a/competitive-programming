// Verifica Bicollatz

#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>


constexpr int n_vecchi = 10;

using namespace std;

int A, B;

void leggi_input() {ifstream("input.txt") >> A >> B;}
void scrivi_output(int risultato) {ofstream("output.txt") << risultato;}

int calcola_bicollatz();

int main()
{
    leggi_input();
    scrivi_output(calcola_bicollatz());
}

int calcola_bicollatz()
{
    // la morale della congettura è quella che quasi ogni coppia di numeri
    // può essere trasformata in una coppia di potenze di 2 uguali.
    
    int op;
    // ogni "n_vecchi" operazioni stilerà un vettore di n_vecchi elementi
    // che conterranno i numeri di calcolo precedenti
    int vecchi[n_vecchi][2];
    
    for(op = 0; A != 1 || B != 1; op++)
    {   
        // Entrambi pari, divide per 2
        if(A % 2 == 0 && B % 2 == 0) {
            A /= 2;
            B /= 2;
        }
        
        // Entrambi dispari, fa 3n + 1
        else if(A % 2 == B % 2 == 1)
            A = 3 * A + 1, B = 3 * B + 1;
        
        else {
            A = A % 2 ? A + 3 : A;
            B = B % 2 ? B + 3 : B;
        }
        cout << A << ' ' <<  B << endl;
        
        // Se trova la coppia nel vettore vecchi
        if(op >= n_vecchi && find_if(vecchi, vecchi + 10, [&](int* elem){return elem[0] == A && elem[1] == B;}) != vecchi + 10)
            return -1;
        // altrimenti aggiunge la coppia nel vettore
        else if (op >= n_vecchi)
            vecchi[op % n_vecchi][0] = A;
            vecchi[op % n_vecchi][1] = B;
    }

    return op;
}