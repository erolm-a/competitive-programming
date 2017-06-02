#include <fstream>
#include <vector>

using namespace std;

void leggi_input();
void scrivi_output(int risultato) {ofstream("output.txt") << risultato;}

int rollercoaster();

vector<int> piloni;
int main()
{
    leggi_input();
    scrivi_output(rollercoaster());

    return 0;
}

void leggi_input()
{
    ifstream i_f("input.txt");
    size_t N;
    i_f >> N;

    piloni.resize(N);

    for(size_t i = 0; i < N; i++)
        i_f >> piloni[i];
}

int rollercoaster()
{
    int inerzia = -1;
    size_t pos = 0;

    for(;pos < piloni.size() - 1;)
    {
        // salita o pianeggiante(inerziale)
        if(piloni[pos+1] >= piloni[pos])
        {
            // è una salita motorizzata?
            const int k = piloni[pos+1] - piloni[pos];

            if(pos < piloni.size() - 2 && k > 0 && k == piloni[pos+2] - piloni[pos+1]) {
                for(pos += 2;
                    pos < piloni.size()-1 && k == piloni[pos+1] - piloni[pos];
                    ++pos)
                        ;
                inerzia = piloni[pos];
                // è arrivato alla fine o dopo la motorizzata c'è un pilone più alto o uguale
                if(pos == piloni.size() -1 || piloni[pos+1] >= piloni[pos])
                    goto fine;
            }
            // è inerziale?
            else do
            {
                if(piloni[pos+1] >= inerzia)
                    goto fine;
                else pos++;
            }while((pos < piloni.size()-1 && piloni[pos+1] >= piloni[pos])
                   && !(pos < piloni.size()-2 && piloni[pos+2] - piloni[pos+1] == piloni[pos+1] - piloni[pos]));
        }

        // discesa
        else {
            inerzia = piloni[pos];
            do {
                ++pos;
            } while(pos < piloni.size() - 1 && piloni[pos+1] < piloni[pos]);
        }
    }
    fine: return pos;
}
