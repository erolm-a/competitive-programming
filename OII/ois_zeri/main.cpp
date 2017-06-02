// Calcolo degli zeri in coda da una moltiplicazione
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void leggi_input();
void scrivi_output(int risultato) {ofstream("output.txt") << risultato;}

int trova_zeri();

vector<unsigned long> fattori(0);
// fattorizza il numero num. Incrementa le tre variabili del numero di fattori
// corrispondenti
inline void fattorizza(unsigned long& num, int& due, int& cinque);

int main()
{
    leggi_input();
    scrivi_output(trova_zeri());

    return 0;
}

void leggi_input()
{
    ifstream i_f("input.txt");
    unsigned long fatt;
    while(i_f >> fatt) {
        fattori.push_back(fatt);

        if(i_f.peek() == 'x')
            i_f.ignore();
    }
}

int trova_zeri()
{
    int due = 0, cinque = 0;

    for(auto& i: fattori)
        fattorizza(i, due, cinque);

    return (due > cinque ? cinque : due);
}

void fattorizza(unsigned long &num, int &due, int &cinque)
{
    // prima prova a dividere per dieci, poi per cinque, infine per due.
    // la divisione per due è la più veloce per via dello shift a destra

    // Fa la maschera dei bit per filtrare l'ultimo, poi lo controlla
    while(!((num & 1) ^ 0)) {
        num >>= 1;
        due++;
    }
    while(num%5 == 0) {
        num /= 5;
        cinque++;
    }
}
