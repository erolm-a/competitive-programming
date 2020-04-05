#include <bits/stdc++.h>

typedef enum {
    SOPRA = 0,
    DESTRA = 1,
    SOTTO = 2,
    SINISTRA = 3
} parete_t; // lato

typedef struct {
    parete_t lato;
    int posizione;
} foro_t; // posizione

typedef struct {
    int o; char orient;
} specchio_t;

using namespace std;

parete_t changedir(char ori, parete_t verso) {
    switch(ori) {
    case '/': switch(verso) {
        case SOPRA: return DESTRA;
        case SOTTO: return SINISTRA;
        case DESTRA: return SOPRA;
        case SINISTRA: return SOTTO;
        }
    case '\\': switch(verso) {
        case SOPRA: return SINISTRA;
        case SOTTO: return DESTRA;
        case DESTRA: return SOTTO;
        case SINISTRA: return SOPRA;
        }
    default: assert(false);
        return SOPRA; // palliativo
    }
}

#define MAX_Q 1000001
struct node {
    int c; specchio_t s{}; vector<int> nxt, prv; int ch_axis;
}_alloc[MAX_Q];

int _id_al;

struct skiplist {
    int begin, end;

    skiplist()
    {
        begin = _id_al++;
        _alloc[begin].c = INT_MIN;
        end   = _id_al++;
        _alloc[end].c = INT_MAX;
        _alloc[begin].nxt = {end};
        _alloc[begin].prv = {-1};
        _alloc[end].nxt = {-1};
        _alloc[end].prv = {begin};
    }

    int find(int x) {
        int cur = begin;
        int cl = _alloc[begin].nxt.size();
        while(cl >= 0) {
            while(cl < _alloc[cur].nxt.size() && _alloc[_alloc[cur].nxt[cl]].c<x) cur = _alloc[cur].nxt[cl];
            cl--;
        }
        return _alloc[cur].nxt[0]; // che è l'elemento >= x più a sinistra
    }


    int insert(int c, specchio_t s) {
        int r=find(c);
        int l=_alloc[r].prv[0];
        int it = _id_al++;
        _alloc[it].c = c;
        _alloc[it].s = s;
        int limit = ffs(rand());
        while(limit > _alloc[begin].nxt.size()) {
            _alloc[begin].nxt.resize(limit);
            _alloc[end].nxt.resize(limit);
            _alloc[begin].prv.resize(limit);
            _alloc[end].prv.resize(limit);

            /*_alloc[begin].nxt.push_back(-1);
            _alloc[begin].prv.push_back(-1);
            _alloc[end].nxt.push_back(-1);
            _alloc[end].prv.push_back(-1);
            */
        }

        for(int cl = 0; cl < limit; cl++)
        {
            while(cl>=_alloc[l].nxt.size()) l = _alloc[l].prv[cl-1];
            while(cl>=_alloc[r].prv.size()) r = _alloc[r].nxt[cl-1];
            _alloc[l].nxt[cl] = it;
            _alloc[r].prv[cl] = it;
            _alloc[it].nxt.push_back(r);
            _alloc[it].prv.push_back(l);
        }
        return it;
    }
};

vector<skiplist> horiz, vert;
int R, C;

void inizia(int R, int C) {
    ::R = R, ::C = C;
    srand((unsigned) time(nullptr));
    horiz.resize(R);
    vert.resize(C);
}

void aggiungi(int riga, int colonna, char orientamento) {
    int a = horiz[riga].insert(colonna, {colonna, orientamento});
    int b = vert[colonna].insert(riga, {riga, orientamento});
    _alloc[a].ch_axis = b;
    _alloc[b].ch_axis = a;
}

inline int get_row(int col) {return _alloc[col].ch_axis;}

inline int get_col(int row) {return _alloc[row].ch_axis;}


foro_t calcola(foro_t ingresso) {
    int riga = -1, colonna = -1;

    int pos = ingresso.posizione;
    parete_t dir = ingresso.lato;

    switch(dir) {
        case SOPRA:
            colonna = _alloc[vert[pos].begin].nxt[0];
            if(_alloc[colonna].c == INT_MAX) return {SOTTO, pos};
            break;
        case SOTTO:
            colonna = _alloc[vert[pos].end].prv[0];
            if(_alloc[colonna].c == INT_MIN) return {SOPRA, pos};
            break;
        case SINISTRA:
            riga = _alloc[horiz[pos].begin].nxt[0];
            if(_alloc[riga].c == INT_MAX) return {DESTRA, pos};
            break;
        case DESTRA:
            riga = _alloc[horiz[pos].end].prv[0];
            if(_alloc[riga].c == INT_MIN) return {SINISTRA, pos};
            break;
        default: assert(false);
    }

    if(riga != -1) colonna = get_col(riga);
    else if(colonna != -1) riga = get_row(colonna);

    dir = (parete_t)(((int)dir + 2) % 4);

    while(true) {
        // ora riga e colonna puntano allo stesso elemento
        auto s = _alloc[riga].s;
        switch(dir = changedir(s.orient, dir))
        {
            case SOPRA:
                colonna = _alloc[colonna].prv[0];
                if(_alloc[colonna].c == INT_MIN)
                    return {SOPRA, _alloc[riga].c};
                riga = get_row(colonna);
                break;
            case SOTTO:
                colonna = _alloc[colonna].nxt[0];
                if(_alloc[colonna].c == INT_MAX)
                    return {SOTTO, _alloc[riga].c};
                riga = get_row(colonna);
                break;
            case SINISTRA:
                riga = _alloc[riga].prv[0];
                if(_alloc[riga].c == INT_MIN)
                    return {SINISTRA, _alloc[colonna].c};
                colonna = get_col(riga);
                break;
            case DESTRA:
                riga = _alloc[riga].nxt[0];
                if(_alloc[riga].c == INT_MAX)
                    return {DESTRA, _alloc[colonna].c};
                colonna = get_col(riga);
                break;
        }
    }
}
