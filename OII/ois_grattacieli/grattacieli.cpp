// Trova il numero massimo di grattacieli ammirabile

#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

vector<int>altezze(0);

void leggi_input();
void scrivi_output(int risultato) {ofstream("output.txt") << risultato;}

int osserva();

int main()
{
    leggi_input();
    scrivi_output(osserva());
    return 0;
}

void leggi_input()
{
    ifstream input_file("input.txt");
    int N;
    input_file >> N;
    altezze.resize(N);
    
    for(int &i: altezze)
        input_file >> i;
}


int osserva()
{
    // strategia: crea un vettore di "massimi" uguali. Se ne trova solo 1, il numero di grattacieli visibili è pari a N-1;
    // Se sono di più il numero è dato dalla somma delle distanze del grattacielo considerato dagli altri, oppure tra un grattacielo e un limite.
    
    vector<int> massimi(0);
    
    auto primo = max_element(altezze.begin(), altezze.end());
    int max = *primo;
    massimi.push_back(primo - altezze.begin());
    
    
    for(primo += 1; primo != altezze.end(); primo++)
        if(*primo == max)
            massimi.push_back(primo - altezze.begin());
    
    
    int visibili = 0;
    for(int i = 0; i < massimi.size(); i++)
    {
        int destra = 0, sinistra = 0;
        
        // Caso 1: È il primo alla sinistra
        if(i == 0)
            sinistra = massimi[i];
        
        // Caso 2: Non è il primo alla sinistra
        else
            sinistra = massimi[i] - massimi[i-1];
        
        // Caso 3: È l'ultimo grattacielo, ovvero il primo da destra
        if(i + 1 == massimi.size())
            destra = (altezze.size() - 1) - massimi[i];
        else
            destra = massimi[i+1] - massimi[i];
            
        
        if(destra + sinistra + 1 > visibili)
            visibili = destra + sinistra + 1;
    }
    
    return visibili;
}