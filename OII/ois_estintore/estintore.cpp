/* trova il numero di stanze senza estintore
 *
 * Assunzioni: ogni stanza è rettangolare, con all'interno un rettangolo di punti;
 * Le stanze possono avere una grandezza minima di 1, quindi devono avere almeno un carattere . o #;
 * Inoltre non si presume che i muri delle stanze non siano nella stessa riga;
 *
 * Esempio:
	########
	#..#...#
	#..#...#
	####...#
	########
	#.##..@#
	#.##...#
	####...#
	########
 *
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// matrice di caratteri
char pianta[1000][1000];

int M, N;

// Struttura stanze: le coordinate della stanza, a partire dal
// '.'/'#' in alto a sinistra fino a quello a destra.
// Nell'esempio in alto potrebbe essere: {Xa = 4, Ya = 1, Xb = 6, Yb = 3}
struct stanza{int Xa, Xb, Ya, Yb;};

// stanze vuote
int stanze_vuote = 0;

// funzioni di I/O
void leggi_input();
void scrivi_output() {ofstream("output.txt") << stanze_vuote;}

bool estintore_trovato = false;

void calcola_estintori();
/* trova la prima stanza disponibile, altrimenti da come risultato {-1, -1, -1, -1};
 * inoltre trova l'estintore
 * il parametro indica la riga da cui iniziare a cercare: all'inizio ha valore 1
 * in seguito aumenta il valore in base all'ultima stanza cancellata
*/
stanza trova_stanze(int inizio_riga);

int main()
{
	leggi_input();
	calcola_estintori();
	scrivi_output();
}

void leggi_input()
{
	ifstream input_file("input.txt");
	input_file >> M >> N;


	for(int i = 0; i < M; i++)
		for(int j = 0; j < N; j++)
			input_file >> pianta[i][j];
}


void calcola_estintori()
{
    stanza prima_stanza;

    int ultima_riga = 1;
    // itera ogni stanza e verifica se trova un estintore
    while((prima_stanza = trova_stanze(ultima_riga)).Xa != -1)
    {
        if(!estintore_trovato)
            stanze_vuote++;

        // cancella la stanza
        for(int i = prima_stanza.Ya; i <= prima_stanza.Yb; i++)
            for(int j = prima_stanza.Xa; j <= prima_stanza.Xb; j++)
                pianta[i][j] = '#';
                    
        ultima_riga = prima_stanza.Ya;
        estintore_trovato = false;
    }
}

stanza trova_stanze(int inizio_riga)
{
	stanza ultima_stanza {-1, -1, -1, -1};

	// Trova la prossima stanza
	int Xa, Ya;
	for(Ya = inizio_riga; Ya < M; Ya++)
		for(Xa = 1; Xa < N; Xa++)
			if(pianta[Ya][Xa] == '.' || pianta[Ya][Xa] == '@')
			{
				ultima_stanza.Xa = Xa, ultima_stanza.Ya = Ya;
				goto calcola_dim;
			}

	calcola_dim:

		// Se è stata trovata una stanza
		// calcola le dimensioni e cerca l'estintore;

	if(ultima_stanza.Xa != -1) {
            int Xb, Yb;
            for(Yb = Ya; pianta[Yb][Xa] != '#'; Yb++)
                for(Xb = Xa; pianta[Yb][Xb] != '#'; Xb++){
                    // se trova un estintore 
                    if(pianta[Yb][Xb] == '@')
                        estintore_trovato = true;
                }
                
            Xb--, Yb--;
	
            ultima_stanza.Xb = Xb;
            ultima_stanza.Yb = Yb;
	}

	return ultima_stanza;
}