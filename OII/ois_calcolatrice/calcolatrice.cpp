#include <cstdlib> // per atoi()
#include <fstream>
#include <string>

using namespace std;

const char* input_name = "input.txt";
const char* output_name = "output.txt";

// funzioni di I/O
string leggi_input();
void scrivi_output(int N);
void scrivi_output(string N);

// Dato un numero da 0 a 9 in formato carattere, la funzione restituisce
// l'inverso LCD se possibile, -1 se no.
int inverti_carattere(char ch);

// la funzione resistuisce la stringa in formato invertito se possibile,
// altrimenti genera un'eccezione
string inverti_stringa(string N_orig);

// eccezione
struct Non_invertible {};

int main()
{
    string N = leggi_input();
    try {
        int N_inv = atoi(inverti_stringa(N).c_str());
        // converte la stringa originaria in intero
        int N_Orig_int = atoi(N.c_str());
        // se il numero N_inv è più piccolo allora lo scrive, altrimenti
        // da l'altro
        if(N_Orig_int >= N_inv)
            scrivi_output(N_inv);
        else scrivi_output(N);
    }
    catch(Non_invertible)
    {
        scrivi_output(N);
    }
    return 0;
}

string leggi_input()
{
    string N;
    ifstream inp(input_name);
    inp >> N;
    return N;
}

void scrivi_output(int N) {
    ofstream out(output_name);
    out << N << endl;
}

void scrivi_output(string N) {
    ofstream out(output_name);
    out << N << endl;
}

string inverti_stringa(string N_orig)
{
    // legge la stringa al contrario, verifica ogni singolo carattere e
    // verifica alla fine il risultato
    
    string N_nuovo;
    for(auto p = N_orig.rbegin(); p != N_orig.rend(); p++)
    {
        int cifra = inverti_carattere(*p);
        if(cifra < 0)
            throw Non_invertible();
        N_nuovo.push_back('0' + cifra);
    }
    
    if(N_nuovo[0] == '0')
        throw Non_invertible();
    
    return N_nuovo;
}

int inverti_carattere(char ch)
{
    switch(ch) {
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': case '4': case '7': return -1;
        case '5': return 5;
        case '6': return 9;
        case '8': return 8;
        case '9': return 6;
        default: return -1;
    }
}