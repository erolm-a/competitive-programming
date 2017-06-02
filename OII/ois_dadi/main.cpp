#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std;

#define MAX_N 100000
int main()
{
    char comandi[MAX_N + 1];
    int N;
    ifstream i_f("input.txt");
    i_f >> N >> comandi;

    int risposte[MAX_N];

    int fronte = 2, su = 1, dx = 3, retro = 5, sx = 4, giu = 6, t, j = 0;
    for(int i = 0; i < N; i++) {
        switch(comandi[i]) {
            case 'F':
                risposte[j++] = fronte;
                break;
            case 'T':
                risposte[j++] = su;
                break;
            case 'R':
                risposte[j++] = dx;
                break;
            case 'X':
                t = su;
                su = retro;
                retro = giu;
                giu = fronte;
                fronte = t;
            break;
            case 'Y':
                t = su;
                su = dx;
                dx = giu;
                giu = sx;
                sx = t;
            break;
            case 'Z':
                t = fronte;
                fronte = sx;
                sx = retro;
                retro = dx;
                dx = t;
            break;
        }
    }

    ofstream o_f("output.txt");
    ostream_iterator<int> it(o_f, " ");
    copy(risposte, risposte + j, it);
    o_f << '\n';
    return 0;
}
