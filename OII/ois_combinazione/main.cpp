#include <fstream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

void leggi_input();
void scrivi_output(long long risultato) {ofstream("output.txt") << risultato;}

typedef pair<int, size_t> interr_t;

bool operator<(interr_t& a, interr_t& b) // necessario per usare la priority_queue
{
    return a.first < b.first;
}

priority_queue<interr_t> interr;

// funzione risolvente
long long premi();

int main()
{
    leggi_input();
    scrivi_output(premi());
}

void leggi_input()
{
    size_t N;
    ifstream i_f("input.txt");

    i_f >> N;

    for(size_t i = 0; i < N; i++) {
        int temp;
        i_f >> temp;
        interr.push((interr_t){temp, i});
    }
}

long long premi()
{
    size_t old_pos = 0;
    long long mosse = 0;

    while(!interr.empty())
    {
        auto new_pos = interr.top().second;
        if(new_pos > old_pos)
            mosse += (new_pos - old_pos);
        else
            mosse += (old_pos - new_pos);
        old_pos = new_pos;
        interr.pop();
    }
    return mosse;
}
