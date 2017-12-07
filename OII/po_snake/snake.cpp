typedef struct
{
    int riga;
    int colonna;
} cella_t;

typedef enum
{
    SOPRA,
    SOTTO,
    DESTRA,
    SINISTRA
} direzione_t;

cella_t posizione_mela(); // NON SERVI A NULLA

void muovi(direzione_t);

void play_horiz();
void play_vert();
static int R, C;
void gioca(int R, int C)
{
    ::R = R, ::C = C;
    if(R % 2)
        play_horiz();
    play_vert();
}

void play_horiz()
{
    while(1) {
        for(int i = 0; i < C-1; i++)
            muovi(DESTRA);
        muovi(SOTTO);
        for(int i = C-1; i >= 0; i--) {
            for(int j = 1; j < R-1; j++)
                if(i % 2 == 1)
                    muovi(SOTTO);
                else muovi(SOPRA);
            if(i > 0)
                muovi(SINISTRA);
        }
        muovi(SOPRA);
    }
}
void play_vert()
{
    while(1) {
        for(int i = 0; i < R-1; i++)
            muovi(SOTTO);
        muovi(DESTRA);
        for(int i = R-1; i >= 0; i--) {
            for(int j = 1; j < C-1; j++)
                if(i % 2 == 1)
                    muovi(DESTRA);
                else muovi(SINISTRA);
            if(i > 0)
                muovi(SOPRA);
        }
        muovi(SINISTRA);
    }
}
