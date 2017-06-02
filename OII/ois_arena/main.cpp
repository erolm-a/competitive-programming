#include <fstream>
#include <algorithm>

using namespace std;

#define MAX_N 100000

int main()
{
    int general_damage = 0, count = 0, N, E, L;
    int players[MAX_N];

    ifstream i_f("input.txt");
    i_f >> N >> E >> L;
    fill(players, players + N, L);
    for(int i = 0; i < E; i++) {
        int pl; char comm;
        i_f >> pl >> comm;
        if(comm == 'f') {
            int pl2;
            i_f >> pl2;
            players[pl2]--;
        }
        else
            general_damage++, players[pl]++;
    }
    for(int i = 0; i < N; i++)
        if(players[i] - general_damage > 0)
            count++;
    ofstream("output.txt") << count << '\n';
    return 0;
}
