// robot: conta il numero di mosse prima di un ciclo.
#include <iostream>
#include <fstream>

using namespace std;

constexpr char RUOTA_SINISTRA = 'L';
constexpr char RUOTA_DESTRA = 'R';
constexpr char AVANTI = '+';
constexpr char AVANTI2 = 'O';
constexpr char FINE = 'X';

enum direzioni{
    SU = 0,
    DESTRA,
    GIU,
    SINISTRA
};

struct casella {
    char mossa;
    bool direzione[4] {false, false, false, false};
};

// definisce il piano
int M, N;
casella piano[500][500];

void leggi_input();
void scrivi_output(int risultato) {ofstream("output.txt") << risultato;}

int osserva();
inline void muovi(int &x, int &y, enum direzioni dir);

int main()
{
    leggi_input();
    scrivi_output(osserva);
}

void leggi_input()
{
    ifstream i_f("input.txt");

    i_f >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            i_f >> piano[i][j].mossa;
}

int osserva()
{
    int n_mosse = 0, x = 0, y = 0;
    direzioni dir = DESTRA;

    for(; ;n_mosse++)
    {
        try {
        switch(piano[x][y].mossa)
        {
            case FINE:
                return -1;
            case AVANTI:
                muovi(x, y, dir);
                break;
            case AVANTI2:
                muovi(x, y, dir);
                muovi(x, y, dir);
                break;
            case RUOTA_DESTRA:
                switch(dir)
                {
                    case SU:
                        dir = DESTRA;
                        break;
                    case DESTRA:
                        dir = GIU;
                        break;
                    case GIU:
                        dir = SINISTRA;
                        break;
                    case SINISTRA:
                        dir = SU;
                        break;
                }
                muovi(x, y, dir);
                break;
            case RUOTA_SINISTRA:
                switch(dir)
                {
                    case SU:
                        dir = SINISTRA;
                        break;
                    case SINISTRA:
                        dir = GIU;
                        break;
                    case GIU:
                        dir = DESTRA;
                        break;
                    case DESTRA:
                        dir = SU;
                        break;
                }

                muovi(x, y, dir);
                break;
        } // fine switch(mossa)
        } // fine try
        catch(...)
        {
            return n_mosse;
        }
    }
}

void muovi(int &x, int &y, enum direzioni dir)
{
    switch (dir) {
    case SU:
        y = y - 1;
        if(y < 0)
            y = N - 1;
        break;
    case DESTRA:
        x = (x + 1) % M;
        break;
    case GIU:
        y = (y + 1) % N;
        break;
    case SINISTRA:
        x = x - 1;
        if(x < 0)
            x = M - 1;
    }
}
