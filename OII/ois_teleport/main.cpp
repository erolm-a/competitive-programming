#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <queue>
#include <utility>

using namespace std;
typedef pair<int, int> pii;
struct State {
    pii pos;
    int t;
};

vector<pii> teleports;
queue<State> stati;

char** mappa;

bool checked[1000][1000];

void elabora(State s) {
    int x = s.pos.second, y = s.pos.first, t = s.t;
    if(checked[y][x] == true)
        return;

    if(mappa[y][x] == '@') {
        for(auto i: teleports) {
            if(i != s.pos) {
                stati.push({i, t+2});
                checked[i.first][i.second] = true;
            }
        }
    }
    stati.push({s.pos, t+1});

    checked[y][x] = true;
}

#define check(y, x) (y >= 0 && y < H && x >= 0 && x < W && mappa[y][x] != '#')

int persuade(int H, int W, char** C) {
    pii start, end;

    mappa = C;
    for(int i = 0; i < H; i++)
        for(int j = 0; j < W; j++)
            switch(C[i][j]) {
                case '@':
                    teleports.push_back(make_pair(i, j));
                    break;
                case 'C':
                    start = make_pair(i, j);
                    break;
                case 'M':
                    end = make_pair(i, j);
                    break;
            }

    stati.push({start, 0});

    while(!stati.empty()) {
        State p = stati.front();
        stati.pop();
        if(p.pos == end)
            return p.t;
        int y = p.pos.first, x = p.pos.second, t = p.t;
        checked[y][x] = true;



        if(check(y-1, x)) elabora({make_pair(y-1, x), t});
        if(check(y+1, x)) elabora({make_pair(y+1, x), t});
        if(check(y, x-1)) elabora({make_pair(y, x-1), t});
        if(check(y, x+1)) elabora({make_pair(y, x+1), t});
    }

    return -1;
}


int main() {
    FILE *fr, *fw;
    int H, W, i;
    char** C;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d%d", &H, &W));
    C = (char**) malloc(H * sizeof(char*));
    for(i=0; i<H; i++) {
        C[i] = (char*) malloc((W + 1) * sizeof(char));
        assert(1 == fscanf(fr, "%s", C[i]));
    }

    fprintf(fw, "%d\n", persuade(H, W, C));
    fclose(fr);
    fclose(fw);
    return 0;
}
