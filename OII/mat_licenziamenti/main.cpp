#include <fstream>
#include <utility>
#include <array>

using namespace std;
// dipendenti

array<pair<int, int>, 100000> dipendenti;
size_t n = 0;
// numero di licenziati
int licenziati = 0;

void leggi_input();
void scrivi_output() {ofstream("output.txt") << licenziati;}

void licenzia();

int main()
{
    leggi_input();
    licenzia();
    scrivi_output();

    return 0;
}

void leggi_input()
{
    ifstream i_f("input.txt");

    i_f >> n;
    for(size_t i = 0; i < n; i++)
        i_f >> dipendenti[i].first >> dipendenti[i].second;
}

void licenzia()
{
    for(auto i = dipendenti.begin(); i < dipendenti.begin() + n; i++)
    {
        for(int brav = i->first, capo = i->second; capo != -1; capo = dipendenti[capo].second)
            if(dipendenti[capo].first < brav) {
                licenziati++;
                break;
            }
    }
}
