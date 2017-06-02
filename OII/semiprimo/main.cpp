#include <iostream>
#include <fstream>
/*
 * Numero semiprimo: numero intero >= 2 fattorizzato (scomposto in numeri primi)
 * come prodotto di due numeri primi (non necessariamente distinti, ovvero il numero
 * può essere pure un quadrato di un numero primo).
 *
 * File di input (input.txt): i numeri semiprimi da fattorizzare, uno per riga.
 * File di output (output.txt): i fattori, ordinati in ordine crescente, oppure -1 se il
 *   numero non è semiprimo
 *
 *
 * La strategia che adotto è quella di verificare se, prima di tutto, il numero non sia < 2 oppure
 * che il numero non sia primo. Altrimenti si va a cercare un fattore che sia divisore di tale numero.
 *
 * 2 <= N <= 1.000.000 quindi è sufficiente usare il tipo int
 * */



using namespace std;

constexpr auto input_path = "input.txt";
constexpr auto output_path = "output.txt";

ifstream input_file;
ofstream output_file;

// test di primalità
bool primo(unsigned int n);
// trova il prossimo divisore primo
unsigned int trova_divisore(unsigned int n);
// scrivi nel file il codice di fallimento oppure i due fattori
void fallimento() {output_file << -1;}
void scrivi(unsigned int fatt1, unsigned int fatt2) {output_file << fatt1 << ' ' << fatt2;}

int main()
{
    input_file.open(input_path);
    output_file.open(output_path);

    if(input_file.is_open())
    {
        if(output_file.is_open())
        {
            unsigned int semiprimo;
            // leggiamo il semiprimo e verifichiamo se è minore di due oppure se è primo
            input_file >> semiprimo;
            if(semiprimo < 2 || primo(semiprimo))
                fallimento();
            // altrimenti tentiamo di fattorizzare il numero cercando il primo divisore di un numero
            unsigned int divisore = trova_divisore(semiprimo);
            // se il divisore è primo e l'altro fattore è primo pure li possiamo scrivere
            if(divisore != semiprimo && primo(semiprimo/divisore))
                scrivi(divisore, semiprimo/divisore);
            else fallimento();
        }
        else cerr << "Impossibile aprire il file " <<  output_path << endl;
    }
    else cerr << "Impossibile aprire il file " << input_path << endl;

    return 0;
}

bool primo(unsigned int n)
{
    for(unsigned int i = 2; i*i <= n; i++)
        if(n % i == 0) return false;
    return true;
}

unsigned int trova_divisore(unsigned int n)
{
    for(unsigned int i = 2; i < n; i++)
        if(n % i == 0 && primo(i))
            return i;
    return n;
}
