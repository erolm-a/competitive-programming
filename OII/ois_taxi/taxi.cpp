#include <vector>
#include <fstream>

using namespace std;

const char *output_name = "output.txt";

// la funzione valuta il percorso 
int valuta_percorso(vector<int> tariffe);


// funzioni di I/O
void leggi_input(int &n_citta, vector<int> &tariffe);
void scrivi_output(int risultato);

int main()
{
    int n;
    vector<int> tariffe;
    leggi_input(n, tariffe);
    scrivi_output(valuta_percorso(tariffe));
    return 0;
}

void leggi_input(int &n_citta, vector<int> &tariffe)
{
    // legge il numero di città e alloca memoria per il vettore
    ifstream input_file("input.txt");
    input_file >> n_citta;
    
    tariffe = vector<int>(n_citta);
    
    // legge le tariffe di ciascuna città
    for(int i = 0; i < n_citta; i++)
        input_file >> tariffe[i];
}

void scrivi_output(int risultato)
{
    ofstream out_file("output.txt");
    out_file << risultato;
}


int valuta_percorso(vector<int> tariffe)
{
    int tar_corrente, tot = 0;
    
    for(size_t i = 0; i < tariffe.size(); i++)
    {
        // all'inizio inizializza tar_corrente alla tariffa della prima città
        if(i == 0)
            tar_corrente = tariffe[0];

        // se incontra una tariffa migliore
        if(tar_corrente > tariffe[i]) {
            tar_corrente = tariffe[i];
            tot += tar_corrente;
            tar_corrente++;
        }
        
        else {
            tot += tar_corrente;
            tar_corrente++;
        }
            
    }
    return tot;
}
