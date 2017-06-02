// robot: conta il numero di mosse prima di un ciclo.
#include <fstream>
#include <vector>

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

struct posizioni {
	int x, y;
	direzioni d;
	bool operator==(const posizioni& altra)
		{return altra.x == x && altra.y == y && altra.d == d;}
	bool operator!=(const posizioni& altra)
		{return !(*this == altra);}
};

vector<posizioni> vecchi(0);

// definisce il piano
int M, N;
casella piano[500][500];

void leggi_input();
void scrivi_output(int risultato) {ofstream("output.txt") << risultato;}

int osserva();
inline void muovi(int &x, int &y, direzioni dir);

int main()
{
    leggi_input();
    scrivi_output(osserva());
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
    int x = 0, y = 0;
    direzioni dir = DESTRA;

    for(; ;)
    {
    	if(piano[y][x].direzione[dir]) // ricostruisce la catena
    	{
		auto p = vecchi.rbegin();
		posizioni rif {x, y, dir};
		for(; p != vecchi.rend() && *p != rif; p++);
			;
		return p - vecchi.rbegin() + 1;
	}
    	else {
    	   piano[y][x].direzione[dir] = true;
	   vecchi.push_back((posizioni){x, y, dir});
	}
        switch(piano[y][x].mossa)
        {
            case FINE:
                return -1;
            case AVANTI:
                muovi(x, y, dir);
                break;
            case AVANTI2:
                muovi(x, y, dir);
		vecchi.push_back((posizioni){x, y, dir});
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
    } // fine for
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
