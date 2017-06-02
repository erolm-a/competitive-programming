#include <fstream>
#include <queue>

using namespace std;

priority_queue<int> negativi;
int bilancio;

void leggi_input();
void scrivi_output(int risultato) {ofstream("output.txt") << risultato;}
int sfanga();

int main()
{
    leggi_input();
    scrivi_output(sfanga());
}

void leggi_input()
{
    ifstream i_f("input.txt");

    int N;
    i_f >> N;

    for(;N > 0; N--)
    {
        int valore;
        i_f >> valore;
        // se è negativo lo mette nella coda, invertito.
        if(valore < 0)
            negativi.push(-valore);
        bilancio += valore;
    }
}


int sfanga()
{
    // se il bilancio di per sè è gia positivo
    if(bilancio > 0)
        return 0;

    int ritocchi;
    for(ritocchi = 1; (bilancio += 2*negativi.top()) < 0; ritocchi++)
        negativi.pop();

    return ritocchi;
}
