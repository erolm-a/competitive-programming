// esegue la costruzione di un server nel posto appropriato

#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;
// funzioni di I/O
// legge le altitudini e le salva nel vettore
void leggi_input(vector<int> &altitudini, int &K);

void scrivi_output(int risultato){ofstream("output.txt") << risultato;}

// calcola la differenza minima che soddisfa le condizioni richieste
int calcola_minimo(vector<int> &altitudini, int K);

int main()
{
    vector<int> altitudini(0);
    int K;
    leggi_input(altitudini,K);
    scrivi_output(calcola_minimo(altitudini, K));
}

void leggi_input(vector<int> &altitudini, int &K)
{
    ifstream input_file("input.txt");
    int N;
    input_file >> N;
    altitudini.resize(N);
    input_file >> K;
    
    // legge gli elementi
    for(auto p = altitudini.begin(); p != altitudini.end(); p++)
        input_file >> (*p);
}

int calcola_minimo(vector<int> &altitudini, int K)
{
    int min, max, min_diff;
    max = *(max_element(altitudini.begin(), altitudini.begin() + K));
    min = *(min_element(altitudini.begin(), altitudini.begin() + K));
    min_diff = max - min;
    
    
    for(int i = 1; i < altitudini.size() - K; i++)
    {
        // una volta che viene scartato l'elemento più a sinistra
        // si chiede se fosse stato un minimo o un massimo e in tal caso
        // ricalcola
        
        if(altitudini[i - 1] == min || altitudini[i - 1] == max)
        {
            max = *(max_element(&altitudini[i], &altitudini[i + K]));
            min = *(min_element(&altitudini[i], &altitudini[i + K]));
        }
        
        // se il nuovo elemento più a destra ha tutte le caratteristiche
        // per essere un nuovo minimo o un nuovo massimo allora lo prende
        else if(altitudini[i + K - 1] > max)
            max = altitudini[i + K - 1];
        
        else if(altitudini[i + K - 1] < min)
            min = altitudini[i + K - 1];
        
        
        // prende la differenza minore
        if(max - min < min_diff)
            min_diff = max - min;
    }
     
    return min_diff;
}