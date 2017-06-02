// Dato l'preordine e il postordine di un albero binario completo
// trovare l'inordine
// Complessità: O(N)

#include <algorithm>
static int size, *PRE, *POST;

// preindex permette di iterare tra i vari elementi del preordine tra le varie
// ricorsioni. È globale per evitare overhead
static int preindex = 0;

/* l'albero binario è sviluppato in un vettore.
 * L'indice del vettore è l'etichetta, mentre dx e sx corrispondono agli indici
 * (e pertanto alle etichette) dei nodi figli (valgono entrambi zero sono
 * foglie)
 */

#define MAX_N 1000000
struct nodo {
    int dx = 0, sx = 0;
} tree[MAX_N + 1];

// dato un nodo i, trova l'indice j tale che POST[j] = i
int ammortizzato[MAX_N];

/* Costruisce un sottoalbero dal preorder e dal postorder
 * l e h sono due indici che selezionano l'intervallo [l, h) del vettore
 * di postordine.
 */

int build_tree(int l, int h)
{
    // caso base: abbiamo esaurito la ricerca del preordine
    if(preindex >= size)
        return 0;

    int root = PRE[preindex++];

    // caso base: la partizione del postordine è vuota. Pertanto il nodo non
    // può avere figli
    if(h == l)
        return root;

    int j = ammortizzato[PRE[preindex]];

    // nel caso sia possibile partizionare il postordine,
    // effettua la partizione e ricorri
    if(j < h)
        tree[root].sx = build_tree(l, j), tree[root].dx = build_tree(j+1, h);
    return root;
}

int *SIMM;

void inorder(int root)
{
    if(tree[root].sx)
        inorder(tree[root].sx);
    *(SIMM++) = root;
    if(tree[root].dx)
        inorder(tree[root].dx);
}

void visita(int N, int *PRE, int *POST, int *SIMM)
{
    size = N;
    ::PRE = PRE;
    ::POST = POST;
    ::SIMM = SIMM;

    for(int i = 1; i <= N; i++)
        ammortizzato[POST[i]] = i;

    int albero = build_tree(0, size);
    inorder(albero);
}
