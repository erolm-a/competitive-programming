#include <fstream>

using namespace std;

#define MAX_N 100000
int S[MAX_N];
int sol[MAX_N];

int N;
ifstream i_f;
ofstream o_f;

struct fenwick {
    int tree[MAX_N + 1];
    void update(int i) {
        while(i <= N) {
            ++tree[i];
            i += (i & -i);
        }
    }
    int query(int i) {
        int ris = 0;
        while(i > 0) {
            ris += tree[i];
            i -= (i & -i);
        }
        return ris;
    }
}f_right, f_left;

// facciamolo con Fenwick
void right()
{
    int max_n = S[0];
    for(int i = 0; i < N; ++i)
    {
        if(max_n < S[i])
            max_n = S[i];
        f_right.update(S[i]);
        sol[i] += (f_right.query(max_n) - f_right.query(S[i]));
    }
}
void left()
{
    int min_n = S[N-1];
    for(int i = N-1; i >= 0; --i)
    {
        if(min_n > S[i])
            min_n = S[i];
        f_left.update(S[i]);
        sol[i] += (f_left.query(S[i]) - f_left.query(min_n));
    }
}

void calcola()
{
    right();
    left();

    for(int i = 0; i < N; i++)
        o_f << sol[i] << ' ';
}

int main()
{
    i_f.open("input.txt");
    o_f.open("output.txt");
    i_f >> N;
    for(int i = 0; i < N; i++)
        i_f >> S[i];

    calcola();
    o_f << '\n';
    return 0;
}
