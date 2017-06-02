// calcola la carica minima per un'uscita
#include <iostream>
#include <fstream>
#include <utility> // per pair
#include <vector>

using namespace std;

typedef pair<int, int> p_ii;
int M;
vector<p_ii> stazioni;


void leggi_input();
void scrivi_output(int risultato) {ofstream("output.txt") << risultato;}

// funzione risolvente
int minimo();

int main()
{
    leggi_input();
    scrivi_output(minimo());
}

void leggi_input()
{
    ifstream i_f("input.txt");
    int N;
    i_f >> N;
    i_f >> M;

    stazioni.resize(N);

    for(int i = 0; i < N; i++)
        i_f >> stazioni[i].first >> stazioni[i].second;
}

int minimo()
{
    // si stima il minimo al numero iniziale di negativi,
    // e lo si aumenta nel caso ci sia bisogno

    int min = stazioni[0].first, totale = 1;

    for(size_t i = 0; i < stazioni.size() - 1; i++) {
        totale += stazioni[i].second - stazioni[i].first + 1;
        totale -= stazioni[i+1].first - stazioni[i].second - 1;

        if(totale <= 0) {
            min += (-totale + 1);
            totale = 1;
        }
    }

    totale += stazioni.back().second - stazioni.back().first + 1;
    totale -= (M - stazioni.back().second);

    // aumenta min
    if(totale <= 0)
        min += (-totale + 1);

    return min;
}
