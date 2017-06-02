#include <algorithm>
#include <cstdio>
#include <bitset>

#define MAX_N 1000000

static int suc[MAX_N];
static int prec[MAX_N];

static int f_tree[MAX_N+1];

static int N, *ids;

static int classificati[MAX_N];

static std::bitset<MAX_N> squalificato;
void update_f_tree(int i, int v)
{
    i++;
    while(i <= N){
        f_tree[i]+=v;
        i+=(i & -i);
    }
}

int query_f_tree(int i)
{
    i++; int ris = 0;
    while(i > 0)
    {
        ris += f_tree[i];
        i -= (i & -i);
    }
    return ris;
}

void inizia(int N, int ids[]) {
    ::N = N, ::ids = ids;

    for(int i = 0; i < N; i++)
    {
        classificati[ids[i]] = i;
        if(i > 0)
            prec[ids[i]] = ids[i-1];
        else
            prec[ids[i]] = -1;

        if(i < N - 1)
            suc[ids[i]] = ids[i+1];
        else
            suc[ids[i]] = -1;

        update_f_tree(i, 1);
    }
}

void supera(int id) {
    //printf("%d tenta di superare\n", id);
    std::swap(ids[classificati[id]], ids[classificati[prec[id]]]);
    std::swap(classificati[id], classificati[prec[id]]);

    int altro_id = prec[id];
    int prec_prec_id = suc[id];
    suc[id] = altro_id;
    suc[altro_id] = prec_prec_id;
    prec[id] = prec[altro_id];
    prec[altro_id] = id;

    if(suc[altro_id] != -1)
    prec[suc[altro_id]] = altro_id;

    if(prec[id] != -1)
    suc[prec[id]] = id;

    //printf("Classifica attuale\n");
    for(int i = 0; i < N; i++)
    {
        //printf("ID: %d; qualificato: %s\n", ids[i], squalificato[i] ? "No" : "Sì");
    }

}

void squalifica(int id) {
    //printf("%d è squalificato\n", id);
    if(suc[id] != -1)
        prec[suc[id]] = prec[id];
    if(prec[id] != -1)
        suc[prec[id]] = suc[id];

    update_f_tree(classificati[id], -1);
    squalificato[id] = true;

    /*printf("Classifica attuale\n");
    for(int i = 0; i < N; i++)
    {
        printf("ID: %d; qualificato: %s\n", ids[i], squalificato[ids[i]] ? "No" : "Sì");
    }
    */
}

int partecipante(int pos) {
    //printf("Chi partecipa alla posizione %d? ", pos);
    int l = 0, h = N;

    int m;
    while(h != l)
    {
        m = (l + h) / 2;
        int dist = query_f_tree(m);
        if(pos > dist)
            l = m + 1;
        else if(pos < dist || (pos == dist && squalificato[ids[m]]))
            h = m;
        else break; // m è la soluzione
    }
    //printf("%d\n", ids[m]);
    return ids[m];
}
